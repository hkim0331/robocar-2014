#!/usr/bin/env ruby
require 'sequel'

if File.exists?("../db/development.sqlite3")
  ROBOCAR = Sequel.sqlite("../db/development.sqlite3")
else
  raise "does not exist ../db/development.sqlite3"
end
if File.exists?(ARGV[0])
  GRADING = Sequel.sqlite(ARGV[0])[:gradings]
else
  raise "does not find db file."
end

gid = Hash.new
ROBOCAR[:groups].each do |g|
  next if g[:id]==1
  g[:members].split.each do |m|
    gid[m.to_i]=g[:id]
  end
end
#gid.each do |s,g|
#  puts "#{s} belongs #{g}"
#end

jname = Hash.new
File.foreach("exam/all-by-yoshino.csv") do |line|
  next if line =~ /^#/
  empty,name,sid,rest = line.split(/,/)
  jname[sid.to_i] = name
end
#jname.each do |s,j|
#  puts "#{s} #{j}"
#end

ROBOCAR[:students].each do |s|
  next if s[:sid] =~ /(hkimura)|(yoshino)/
  sid = s[:sid].to_i
  #puts "#{sid} #{jname[sid]} #{gid[sid]}"
  if jname[sid].nil?
    puts "#{sid} does not have name."
  else
    GRADING.insert(:sid => sid, :jname => jname[sid], :gid => gid[sid])
  end
end

