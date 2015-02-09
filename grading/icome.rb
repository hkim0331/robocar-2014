#!/usr/bin/env ruby
require 'sequel'

grading = Sequel.sqlite("robocar-2014.db")[:gradings]

File.foreach("icome.txt") do |line|
  sid,icome = line.chomp.split(/\|/)
  grading.where(:sid => sid.to_i).update(:icome => icome.to_i)
end
