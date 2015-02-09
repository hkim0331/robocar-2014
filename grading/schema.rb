# encoding: UTF-8
# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your
# database schema. If you need to create the application database on another
# system, you should be using db:schema:load, not running all the migrations
# from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended to check this file into your version control system.

ActiveRecord::Schema.define(:version => 20140129052759) do

  create_table "advices", :force => true do |t|
    t.text     "body"
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

  create_table "cars", :force => true do |t|
    t.integer  "condition"
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

  create_table "exercises", :force => true do |t|
    t.string   "sid",        :null => false
    t.string   "path",       :null => false
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

  create_table "groups", :force => true do |t|
    t.string   "name"
    t.string   "members"
    t.integer  "car_id"
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

  add_index "groups", ["name"], :name => "index_groups_on_name", :unique => true

  create_table "icomes", :force => true do |t|
    t.string   "sid"
    t.datetime "attend_at"
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

  create_table "lents", :force => true do |t|
    t.integer  "car_id"
    t.date     "lent_on"
    t.date     "willback_on"
    t.date     "back_on"
    t.string   "sid"
    t.string   "contact"
    t.text     "note"
    t.datetime "created_at",                 :null => false
    t.datetime "updated_at",                 :null => false
    t.integer  "condition",   :default => 2
  end

  create_table "students", :force => true do |t|
    t.string   "name"
    t.string   "sid"
    t.string   "uid"
    t.string   "email"
    t.integer  "group_id"
    t.datetime "created_at",      :null => false
    t.datetime "updated_at",      :null => false
    t.string   "password_digest"
  end

  add_index "students", ["sid"], :name => "index_students_on_sid", :unique => true
  add_index "students", ["uid"], :name => "index_students_on_uid", :unique => true

  create_table "weeks", :force => true do |t|
    t.integer  "iteration",  :null => false
    t.string   "c1"
    t.string   "c2"
    t.string   "c3"
    t.string   "c4"
    t.text     "content"
    t.text     "note"
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

end
