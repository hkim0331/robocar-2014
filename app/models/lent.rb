# -*- coding: utf-8 -*-
class Lent < ActiveRecord::Base
  attr_accessible  :car_id, :condition,
    :sid, :contact,
    :lent_on, :willback_on, :back_on,
    :note

  validates :car_id, :sid, :contact, presence: true

  Free = 1
  Lent = 2
  Returned = 3
  Broken = -1

  Conditions = {Free => "空", Lent => "貸", Returned => "R",
    Broken => "B"}

end
