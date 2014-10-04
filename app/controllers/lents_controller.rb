# -*- coding: utf-8 -*-
class LentsController < ApplicationController
  skip_before_filter :authorize, only: [:index]

  # GET /lents
  # GET /lents.json
  def index
    @lents =  if params[:all]
      Lent.order("updated_at DESC")
    else
      Lent.where(:condition => Lent::Lent).order(:car_id)
    end
    @today = Date.today

    respond_to do |format|
      format.html # index.html.erb
      format.json { render json: @lents }
    end
  end

  # GET /lents/1
  # GET /lents/1.json
  def show
    @lent = Lent.find(params[:id])

    respond_to do |format|
      format.html # show.html.erb
      format.json { render json: @lent }
    end
  end

  # GET /lents/new
  # GET /lents/new.json
  def new
    unless session[:admin]
      redirect_to lents_url
      return
    end

    @lent = Lent.new
    @free_cars = Car.where(condition: Car::Free).map{|x| x[:id]}

    respond_to do |format|
      format.html # new.html.erb
      format.json { render json: @lent }
    end
  end

  # GET /lents/1/edit
  def edit
    @lent = Lent.find(params[:id])
  end

  # FIXME: routes
  def returned
    @lent = Lent.find(params[:id])
  end

  # POST /lents
  # POST /lents.json
  def create
    # bugfix.
    if params[:lent][:contact].empty? or params[:lent][:sid].empty?
      redirect_to '/lents/new', notice:'学生番号もしくは連絡先が空です。'
      return
    end
    #
    @lent = Lent.new(params[:lent])
    Car.find(@lent[:car_id]).update_attribute(:condition, Car::Lent)

    respond_to do |format|
      if @lent.save
        format.html { redirect_to lents_url, notice: 'Lent was successfully created.' }
        format.json { render json: @lent, status: :created, location: @lent }
      else
        format.html { render action: "new" }
        format.json { render json: @lent.errors, status: :unprocessable_entity }
      end
    end
  end

  # PUT /lents/1
  # PUT /lents/1.json
  def update
    @lent = Lent.find(params[:id])
    car = Car.find(@lent[:car_id])

    respond_to do |format|
      if (@lent.update_attributes(params[:lent]) and car.update_attributes(:condition => Car::Free))
        format.html { redirect_to lents_url, notice: 'Lent was successfully updated.' }
        format.json { head :no_content }
      else
        format.html { render action: "edit" }
        format.json { render json: @lent.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /lents/1
  # DELETE /lents/1.json
  def destroy
    @lent = Lent.find(params[:id])
    @lent.destroy

    respond_to do |format|
      format.html { redirect_to lents_url }
      format.json { head :no_content }
    end
  end
end
