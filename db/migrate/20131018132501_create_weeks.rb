class CreateWeeks < ActiveRecord::Migration
  def change
    create_table :weeks do |t|
      t.integer :iteration, :null => false
      t.date :c1
      t.date :c2
      t.date :c3
      t.date :c4
      t.text :content
      t.text :note

      t.timestamps
    end
  end
end
