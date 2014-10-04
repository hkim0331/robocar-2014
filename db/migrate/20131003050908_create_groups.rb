class CreateGroups < ActiveRecord::Migration
  def change
    create_table :groups do |t|
      t.string :name
      t.string :members
      t.integer :car_id

      t.timestamps
    end
  end
end
