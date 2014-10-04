class AdvicesController < ApplicationController
  # GET /advices
  # GET /advices.json
  def index
    @advices = Advice.order("updated_at DESC")

    respond_to do |format|
      format.html # index.html.erb
      format.json { render json: @advices }
    end
  end

  # GET /advices/1
  # GET /advices/1.json
  def show
    @advice = Advice.find(params[:id])

    respond_to do |format|
      format.html # show.html.erb
      format.json { render json: @advice }
    end
  end

  # GET /advices/new
  # GET /advices/new.json
  def new
    @advice = Advice.new

    respond_to do |format|
      format.html # new.html.erb
      format.json { render json: @advice }
    end
  end

  # GET /advices/1/edit
  def edit
    @advice = Advice.find(params[:id])
  end

  # POST /advices
  # POST /advices.json
  def create
    @advice = Advice.new(params[:advice])

    respond_to do |format|
      if @advice.save
#        format.html { redirect_to @advice, notice: 'Advice was successfully created.' }
        format.html { redirect_to advices_path}
        format.json { render json: @advice, status: :created, location: @advice }
      else
        format.html { render action: "new" }
        format.json { render json: @advice.errors, status: :unprocessable_entity }
      end
    end
  end

  # PUT /advices/1
  # PUT /advices/1.json
  def update
    @advice = Advice.find(params[:id])

    respond_to do |format|
      if @advice.update_attributes(params[:advice])
        format.html { redirect_to @advice, notice: 'Advice was successfully updated.' }
        format.json { head :no_content }
      else
        format.html { render action: "edit" }
        format.json { render json: @advice.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /advices/1
  # DELETE /advices/1.json
  def destroy
    @advice = Advice.find(params[:id])
    @advice.destroy

    respond_to do |format|
      format.html { redirect_to advices_url }
      format.json { head :no_content }
    end
  end
end
