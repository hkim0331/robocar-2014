class IcomesController < ApplicationController
  # GET /icomes
  # GET /icomes.json
  def index
    @icomes = Icome.all

    respond_to do |format|
      format.html # index.html.erb
      format.json { render json: @icomes }
    end
  end

  # GET /icomes/1
  # GET /icomes/1.json
  def show
    @icome = Icome.find(params[:id])

    respond_to do |format|
      format.html # show.html.erb
      format.json { render json: @icome }
    end
  end

  # GET /icomes/new
  # GET /icomes/new.json
  def new
    @icome = Icome.new

    respond_to do |format|
      format.html # new.html.erb
      format.json { render json: @icome }
    end
  end

  # GET /icomes/1/edit
  def edit
    @icome = Icome.find(params[:id])
  end

  # POST /icomes
  # POST /icomes.json
  def create
    @icome = Icome.new(params[:icome])

    respond_to do |format|
      if @icome.save
        format.html { redirect_to @icome, notice: 'Icome was successfully created.' }
        format.json { render json: @icome, status: :created, location: @icome }
      else
        format.html { render action: "new" }
        format.json { render json: @icome.errors, status: :unprocessable_entity }
      end
    end
  end

  # PUT /icomes/1
  # PUT /icomes/1.json
  def update
    @icome = Icome.find(params[:id])

    respond_to do |format|
      if @icome.update_attributes(params[:icome])
        format.html { redirect_to @icome, notice: 'Icome was successfully updated.' }
        format.json { head :no_content }
      else
        format.html { render action: "edit" }
        format.json { render json: @icome.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /icomes/1
  # DELETE /icomes/1.json
  def destroy
    @icome = Icome.find(params[:id])
    @icome.destroy

    respond_to do |format|
      format.html { redirect_to icomes_url }
      format.json { head :no_content }
    end
  end
end
