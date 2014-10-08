#-*- coding: utf-8 -*-
class Group < ActiveRecord::Base
  attr_accessible :car_id, :members, :name
  validates :name, uniqueness: true
  validate :members_are_8chars_unique

  private
  def members_are_8chars_unique
  	valid =
      begin
        members = self.members.split
  		raise "学生番号は半角数字８ケタです。" unless
                members.all?{|x| x =~ /\A\d{8}\Z/}
        members.each do |sid|
        unless Student.find_by_sid(sid)
          raise "#{sid}さんは受講者リストにみつかりません。"
        end
      end

  		Group.select(:members).each do |mem|
        mem.members.split.each do |sid|
          if members.any?{|x| x==sid}
            raise "#{sid}さんはすでに他のグループに入っています。"
          end
        end
      end
  		true
      rescue Exception => ex
  		msg = ex.message
  		valid = false
      end
  	unless valid
      errors.add("メンバー:", msg)
  	end
  end
end
