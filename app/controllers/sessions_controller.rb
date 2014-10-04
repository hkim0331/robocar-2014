#-*- coding: utf-8 -*-
class SessionsController < ApplicationController
  skip_before_filter :authorize

  def new
  end

  def create
    student = Student.find_by_sid(params[:sid])
    if student and student.authenticate(params[:password])
      session[:student_id] = student.id
      # 管理者は hkim あるいは hkimura.
      session[:admin] = (student.sid =~ /^(hkim)|(yoshino)/)
      #
      if session[:previous_url].nil? or session[:previous_url] =~ /logout/
        redirect_to "/"
      else
        redirect_to session[:previous_url], alert: "ログインしました。"
      end
    else
      redirect_to login_url, alert: "学生番号 または パスワードが違います。"
    end
  end

  def destroy
    session[:student_id] = nil
    session[:admin] = false
    # FIXME: ログアウトしましたのダイアログくらい出そう。
    redirect_to "/log_out.html"
  end
end
