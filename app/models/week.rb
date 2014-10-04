# -*- coding: utf-8 -*-
class Week < ActiveRecord::Base
  attr_accessible :c1, :c2, :c3, :c4, :content, :iteration, :note

  # 2013
  WD = { c1: "火２", c2: "火４", c3: "木４" }
end
