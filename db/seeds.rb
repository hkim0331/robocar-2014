# -*- coding: utf-8 -*-
# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)


puts "seed Student"
Student.delete_all
s = 0
File.foreach("data/sid_uid.txt") do |line|
  sid, uid = line.chomp.split(/\s/,2)
  Student.create(sid: sid, uid: uid, password: "robocar", password_confirmation: "robocar");
  print '.'
  s += 1
end
puts "\nadd #{s} students."

Icome.delete_all
i = 0
File.foreach("data/ucome.log") do |line|
  next if line=~/^#/
  attend, sid, time = line.chomp.split(/\s/,3)
  Icome.create(sid: sid, attend_at: time);
  print '.'
  i += 1
end
puts "\nadd #{i} icome entries."

Car.delete_all
Car::Max.times do
  Car.create(condition: Car::Free);
  puts '.'
end

Week.delete_all
(1..16).each do |w|
  Week.create(iteration: w)
  print '.'
end

Lent.delete_all
(1..Car::Max).each do |c|
	Lent.create(car_id: c, condition: Car::Free, sid: 'hkimura', contact: '3457')
  print '.'
end

Group.delete_all
Group.create(name: "2014宇宙の旅", members: "hkimura yoshino")

puts "\ndone"


