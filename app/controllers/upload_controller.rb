#-*- coding: utf-8 -*-
class UploadController < ApplicationController
  skip_before_filter :authorize, only: [:new]

  DESTDIR = File.join(Rails.root, "beuto-bin")

  def index
  end

  def upload
    gid = (Student.find_by_id(session[:student_id]).group_id or
           "unknown")
    if params[:bin].nil? or params[:bin][:name].nil?
      flash[:alert] = "送信失敗：ファイルを選んでいません。"
    elsif params[:bin][:name].original_filename !~ /\.bin\Z/
      flash[:alert] = "送信失敗：バイナリファイルではありません。"
    else
      name = "#{gid}.bin"
      File.open(File.join(DESTDIR, name),"wb") do |f|
        f.write params[:bin][:name].read
      end
      flash[:alert] = "#{name} として送信しました。
この名前のファイルを hkimura PC でロボカーに焼き込んでください。"
    end

    respond_to do |format|
#      format.html { redirect_to upload_url }
      format.html
      format.json
    end
  end

end
