# -*- coding: utf-8 -*-
class ExercisesController < ApplicationController
  # GET /exercises
  # GET /exercises.json
  def index
    unless session[:admin]
      redirect_to "/"
      return
    end
    @exercises = Exercise.all

    respond_to do |format|
      format.html # index.html.erb
      format.json { render json: @exercises }
    end
  end

  # GET /exercises/1
  # GET /exercises/1.json
  def show
    @exercise = Exercise.find(params[:id])

    respond_to do |format|
      format.html # show.html.erb
      format.json { render json: @exercise }
    end
  end

  # GET /exercises/new
  # GET /exercises/new.json
  def new
    @exercise = Exercise.new

    respond_to do |format|
      format.html # new.html.erb
      format.json { render json: @exercise }
    end
  end

  # GET /exercises/1/edit
  def edit
    @exercise = Exercise.find(params[:id])
  end

  # POST /exercises
  # POST /exercises.json
  def create
    # exercises dir に yyyymmdd_gid_name の形式でセーブ。
    gid = Student.find_by_id(session[:student_id]).group_id
    if params[:g_ex].nil? or params[:g_ex][:name].nil?
      flash[:alert] = "送信失敗: ファイルを選んでいません。"
      redirect_to new_exercise_path
      return
    else
      tm = Time.now.strftime("%Y%m%d")
      o_name = params[:g_ex][:name].original_filename
      unless o_name =~ /\.c|(txt)/
        flash[:alert] = "送信失敗: オレが読めるファイルを送信してくれ。"
        redirect_to new_exercise_path
        return
      end
      s_dir = File.join(Exercise::DIR, gid.to_s)
      Dir.mkdir(s_dir) unless File.directory?(s_dir)
      saveto = File.join(s_dir, "#{tm}_#{o_name}")
      #
      File.open(saveto, "w") do |f|
        f.write params[:g_ex][:name].read.force_encoding("utf-8")
      end
      flash[:alert] = "#{o_name} としてアップロードしました。"
    end

    @exercise=Exercise.new(sid: gid, path:saveto)

    respond_to do |format|
      if @exercise.save
#        format.html { redirect_to exercises_path, notice: 'Group Ex was successfully created.' }
        format.html { redirect_to new_exercise_path, alert: 'グループ課題を送信しました。' }
        format.json { render json: @exercise, status: :created, location: @exercise }
      else
        format.html { render action: "new" }
        format.json { render json: @exercise.errors, status: :unprocessable_entity }
      end
    end

  end

  # PUT /exercises/1
  # PUT /exercises/1.json
  def update
    @exercise = Exercise.find(params[:id])

    respond_to do |format|
      if @exercise.update_attributes(params[:exercise])
        format.html { redirect_to @exercise, notice: 'Exercise was successfully updated.' }
        format.json { head :no_content }
      else
        format.html { render action: "edit" }
        format.json { render json: @exercise.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /exercises/1
  # DELETE /exercises/1.json
  def destroy
    @exercise = Exercise.find(params[:id])
    File.unlink(@exercise.path)
    @exercise.destroy

    respond_to do |format|
      format.html { redirect_to exercises_url }
      format.json { head :no_content }
    end
  end
end
