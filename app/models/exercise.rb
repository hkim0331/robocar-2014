class Exercise < ActiveRecord::Base
  attr_accessible :path, :sid

  DIR = if Rails.env == 'production'
            "/srv/robocar/exercises"
        else
            "/Users/hkim/Desktop"
        end

end
