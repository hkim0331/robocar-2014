# -*- coding: utf-8 -*-
class StudentsController < ApplicationController
  skip_before_filter :authorize, only: [:index]

  # GET /students
  # GET /students.json
  def index
    if session[:admin]
      @students = Student.order(:sid)
    elsif session[:student_id]
      @students = [Student.find(session[:student_id])]
    else
      redirect_to login_url, notice: 'Login が必要です。'
      return
    end
    respond_to do |format|
      format.html # index.html.erb
      format.json { render json: @students }
    end
  end

  # GET /students/1
  # GET /students/1.json
  def show
    @student = Student.find(params[:id])
    unless session[:student_id] == @student.id || session[:admin]
      redirect_to students_url, notice: "他のユーザのプロフィールは閲覧できません。"
      # 2013-10-21, return is necessary here.
      return
    end
    @icomes = Icome.find_all_by_sid(@student.sid)
    # 2014-10-22
    personal_dir = File.join(Exercise::PERSONAL_EX,@student.sid)
    puts "personal_dir: #{personal_dir}"
    @s_reports = Dir.glob(File.join(personal_dir,"*"))
    puts "@s_reports: #{@s_reports}"
    #
    @g_reports = Exercise.find_all_by_sid(@student.group_id)
    respond_to do |format|
      format.html # show.html.erb
      format.json { render json: @student }
    end
  end

  # GET /students/new
  # GET /students/new.json
  def new
    @student = Student.new

    respond_to do |format|
      format.html # new.html.erb
      format.json { render json: @student }
    end
  end

  # GET /students/1/edit
  def edit
    @student = Student.find(params[:id])
    unless session[:student_id] == @student.id || session[:admin]
      redirect_to students_url, notice: "他のユーザのプロフィールは編集できません。"
    end
  end

  # POST /students
  # POST /students.json
  def create
    @student = Student.new(params[:student])
    @params_student = params[:student]

    respond_to do |format|
      if @student.save
        format.html { redirect_to @student, notice: 'Student was successfully created.' }
        format.json { render json: @student, status: :created, location: @student }
      else
        format.html { render action: "new" }
        format.json { render json: @student.errors, status: :unprocessable_entity }
      end
    end
  end

  # PUT /students/1
  # PUT /students/1.json
  def update
    @params_student = params[:student]
    @student = Student.find(params[:id])

    respond_to do |format|
      if @student.update_attributes(params[:student])
        format.html { redirect_to students_url, notice: "Student #{@student.sid} was successfully updated." }
        format.json { head :no_content }
      else
        format.html { render action: "edit" }
        format.json { render json: @student.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /students/1
  # DELETE /students/1.json
  def destroy
    alert = nil
    if session[:admin]
      @student = Student.find(params[:id])
      sid = @student.sid
      @student.destroy
      alert = "removed #{sid}."
    else
      alert = "学生はエントリーを削除できないよ。"
    end

    respond_to do |format|
      format.html { redirect_to students_url, notice: alert }
      format.json { head :no_content }
    end
  end
end
