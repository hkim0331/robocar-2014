# -*- coding: utf-8 -*-
class Car < ActiveRecord::Base
  attr_accessible :condition

  Free = 1
  Lent = 2
  Broken = -1

  Conditions = {Free => "free", Lent => "lent", Broken => "broken"}

  Max = 28 # 最大個数 -1 を指定すること。 (group_id +1 % Max) +2 とするため。

end
