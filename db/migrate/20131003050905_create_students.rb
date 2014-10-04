class CreateStudents < ActiveRecord::Migration
  def change
    create_table :students do |t|
      t.string :name
      t.string :sid
      t.string :uid
      t.string :email
      t.string :password
      t.integer :group_id

      t.timestamps
    end
  end
end
