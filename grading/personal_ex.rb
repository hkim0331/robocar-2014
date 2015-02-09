#!/usr/bin/env ruby

require 'sequel'
grading = Sequel.sqlite("robocar-2014.db")[:gradings]

def files(dir)
  Dir.glob("#{dir}/*").count
end

Dir.glob("personal_ex/*").each do |entry|
  sid = entry.sub(/personal_ex\//,'')
  next unless sid =~ /^1/
  puts "#{sid} #{files(entry)}"
  grading.where(:sid => sid.to_i).update(:p_ex => files(entry))
end
