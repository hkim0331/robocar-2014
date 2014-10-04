# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)


puts "seed Student"
Student.transaction do
    Student.delete_all
    File.foreach("data/sid_uid.txt") do |line|
      sid, uid=line.chomp.split(/\s/,2)
      Student.create(sid: sid, uid: uid, password: "robocar", password_confirmation: "robocar");
  end
end

puts "seed Icome"
Icome.delete_all
File.foreach("data/ucome.log") do |line|
  next if line=~/^#/
  cols = line.chomp.split
  if cols.length == 5
    sid, ip, attend = line.chomp.split(/\s/,3)
  elsif cols.length == 6
    sid, uid, ip, attend = line.chomp.split(/\s/,4)
  else
    raise "format error"
  end
  Icome.create(sid: sid, attend_at: attend);
end

puts "seed Car"
Car.transaction do
  Car.delete_all
  Car::Max.times do
    Car.create(condition: Car::Free);
  end
end

puts "seed Week"
Week.delete_all
(1..16).each do |w|
  Week.create(iteration: w)
end

puts "seed Lent"
Lent.delete_all
(1..Car::Max).each do |c|
	Lent.create(car_id: c, condition: Car::Free, sid: 'hkimura', contact: '3457')
end


