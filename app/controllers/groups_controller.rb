# -*- coding: utf-8 -*-
class GroupsController < ApplicationController
  skip_before_filter :authorize, only: [:index,:show]

  # GET /groups
  # GET /groups.json
  def index
    @groups = Group.all

    respond_to do |format|
      format.html # index.html.erb
      format.json { render json: @groups }
    end
  end

  # GET /groups/1
  # GET /groups/1.json
  def show
    @group = Group.find(params[:id])

    respond_to do |format|
      format.html # show.html.erb
      format.json { render json: @group }
    end
  end

  # GET /groups/new
  # GET /groups/new.json
  def new
    @group = Group.new
    respond_to do |format|
      format.html # new.html.erb
      format.json { render json: @group }
    end
  end

  # GET /groups/1/edit
  def edit
    @group = Group.find(params[:id])
  end

  # POST /groups
  # POST /groups.json
  def create
    @group = Group.new(params[:group])
    if Group.last.nil?
      @group.car_id = 1
    else
      # car 0 is for hkimura and yoshino.
      @group.car_id = ((Group.last.id + 1) % Car::Max) + 1
    end

    respond_to do |format|
      if @group.save
        format.html { redirect_to @group, notice: 'Group was successfully created.' }
        format.json { render json: @group, status: :created, location: @group }

        # FIXME: 存在しない sid だったら?
        @group.members.split.each do |sid|
          begin
            Student.find_by_sid(sid).update_attributes({:group_id => @group.id})
          rescue
            raise "does not exist: #{sid}"
          end
        end
      else
        format.html { render action: "new" }
        format.json { render json: @group.errors, status: :unprocessable_entity }
      end
    end
  end

  # PUT /groups/1
  # PUT /groups/1.json
  def update
    @group = Group.find(params[:id])

    respond_to do |format|
      if @group.update_attributes(params[:group])
        format.html { redirect_to @group, notice: 'Group was successfully updated.' }
        format.json { head :no_content }
      else
        format.html { render action: "edit" }
        format.json { render json: @group.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /groups/1
  # DELETE /groups/1.json
  def destroy
    alert = nil
    if session[:student_id] == Student.find_by_sid(Student::Admin).id
      @group = Group.find(params[:id])
      @group.members.split.each do |sid|
        if s = Student.find_by_sid(sid)
          s.update_attributes({:group_id => nil})
        end
      end
      @group.destroy
    else
      alert = 'only admin can destroy.'
    end
 
    respond_to do |format|
      format.html { redirect_to groups_url, alert: alert }
      format.json { head :no_content }
    end
  end
end
