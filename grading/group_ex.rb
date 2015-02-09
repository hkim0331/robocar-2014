#!/usr/bin/env ruby

require 'sequel'
grading = Sequel.sqlite("robocar-2014.db")[:gradings]

def files(dir)
  Dir.glob("#{dir}/*").count
end

Dir.glob("group_ex/*").each do |entry|
  gid = entry.sub(/group_ex\//,'')
  next unless gid =~ /^\d/
  puts "#{gid} #{files(entry)}"
  grading.where(:gid => gid.to_i).update(:g_ex => files(entry))
end
