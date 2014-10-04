class AddUniquenessIndex < ActiveRecord::Migration
  def up
    add_index :students, :sid, :unique => true
    add_index :students, :uid, :unique => true
    add_index :groups, :name, :unique => true
  end

  def down
    remove_index :students, :sid
    remove_index :students, :uid
    remove_index :groups, :name
  end
end
