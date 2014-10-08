# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)


puts "seed Student"
Student.delete_all
File.foreach("data/sid_uid.txt") do |line|
  sid, uid = line.chomp.split(/\s/,2)
  Student.create(sid: sid, uid: uid, password: "robocar", password_confirmation: "robocar");
  print '.'
end

puts "\nseed Icome"
Icome.delete_all
File.foreach("data/ucome.log") do |line|
  next if line=~/^#/
  attend, sid, time = line.chomp.split(/\s/,3)
  Icome.create(sid: sid, attend_at: time);
  print '.'
end

puts "\nseed Car"
Car.transaction do
  Car.delete_all
  Car::Max.times do
    Car.create(condition: Car::Free);
  end
  puts '.'
end

puts "\nseed Week"
Week.delete_all
(1..16).each do |w|
  Week.create(iteration: w)
  print '.'
end

puts "\nseed Lent"
Lent.delete_all
(1..Car::Max).each do |c|
	Lent.create(car_id: c, condition: Car::Free, sid: 'hkimura', contact: '3457')
  print '.'
end

puts '\ndone'


