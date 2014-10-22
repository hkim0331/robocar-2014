class Exercise < ActiveRecord::Base
  attr_accessible :path, :sid

  if Rails.env == 'production'
    DIR = "/srv/robocar-2014/group_ex"
    PERSONAL_EX = "/srv/robocar-2014/upload"
  else
    DIR = "/Users/hkim/Desktop"
    PERSONAL_EX = "/Users/hkim/Desktop"
  end
end
