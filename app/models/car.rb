# -*- coding: utf-8 -*-
class Car < ActiveRecord::Base
  attr_accessible :condition

  Free = 1
  Lent = 2
  Broken = -1

  Conditions = {Free => "free", Lent => "lent", Broken => "broken"}

  # 最大個数 -1 を指定すること。 (group_id +1 % Max) +2 とするため。
  # 姑息だ。もっと正々堂々とプログラムしよう。2014-10-06.
  Max = 35

end
