class CreateLents < ActiveRecord::Migration
  def change
    create_table :lents do |t|
      t.integer :car_id
      t.integer :lent_on
      t.date :willback_on
      t.date :back_on
      t.string :sid
      t.string :contact
      t.text :note

      t.timestamps
    end
  end
end
