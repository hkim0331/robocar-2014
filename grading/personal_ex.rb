#!/usr/bin/env ruby

require 'sequel'
GRADING = Sequel.sqlite(ARGV[0])[:gradings]

def files(dir)
  Dir.glob("#{dir}/*").count
end

Dir.glob("personal_ex/*").each do |entry|
  sid = entry.sub(/personal_ex\//,'')
  next unless sid =~ /^1/
  puts "#{sid} #{files(entry)}"
  GRADING.where(:sid => sid.to_i).update(:p_ex => files(entry))
end
