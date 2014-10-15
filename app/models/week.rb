# -*- coding: utf-8 -*-
class Week < ActiveRecord::Base
  attr_accessible :c1, :c2, :c3, :c4, :content, :iteration, :note

  # 2013
  WD = { c1: "木１(総シス）", c2: "木４（電気）", c3: "火２（制御）", c4: "火４（電気）" }
end
