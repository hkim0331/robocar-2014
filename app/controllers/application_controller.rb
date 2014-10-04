# -*- coding: utf-8 -*-
class ApplicationController < ActionController::Base
  protect_from_forgery
  before_filter :authorize

  Version = "0.3.1"

  #https://github.com/plataformatec/devise/wiki/How-To:-Redirect-back-to-current-page-after-sign-in,-sign-out,-sign-up,-update
  after_filter :store_location

  def store_location
    # store last url - this is needed for post-login redirect to whatever the user last visited.
    if (request.fullpath != "/login" && \
        request.fullpath != "/users/sign_up" && \
        request.fullpath != "/users/password" && \
        !request.xhr?) # don't store ajax calls
      session[:previous_url] = request.fullpath
    end
  end

  def after_sign_in_path_for(resource)
    session[:previous_url] || root_path
  end

  private
  def authorize
    unless Student.find_by_id(session[:student_id])
      redirect_to login_url, notice: "ログインが必要です。"
    end
  end
end
