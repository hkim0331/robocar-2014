# -*- coding: utf-8 -*-
class Car < ActiveRecord::Base
  attr_accessible :condition

  Free = 1
  Lent = 2
  Broken = -1

  Conditions = {Free => "free", Lent => "lent", Broken => "broken"}

  # これはcar_id ではなく、剰余演算の分母。
  Max = 36

end
