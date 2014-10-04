#-*- coding: utf-8 -*-
class UploadController < ApplicationController
  skip_before_filter :authorize, only: [:new]

  if Rails.env == "development"
    DESTDIR = File.join(Rails.root,"upload")
  else
    DESTDIR = "/srv/robocar/upload"
  end

  def index
  end

  def upload
    gid = Student.find_by_id(session[:student_id]).group_id
    if params[:bin].nil? or params[:bin][:name].nil?
      flash[:alert] = "送信失敗：ファイルを選んでいません。"
    elsif params[:bin][:name].original_filename !~ /\.bin\Z/
      flash[:alert] = "送信失敗：バイナリファイルではありません。"
    else
#      name = "#{gid}_#{Time.now.to_i % 10000}.bin"
      name = "#{gid}.bin"
      File.open(File.join(DESTDIR, name),"wb") do |f|
        f.write params[:bin][:name].read
      end
      flash[:alert] = "#{name} としてアップロードしました。"
    end

    respond_to do |format|
      format.html { redirect_to upload_url }
      format.json
    end
  end

end
