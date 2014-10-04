class CreateExercises < ActiveRecord::Migration
  def change
    create_table :exercises do |t|
      t.string :sid, :null => false
      t.string :path, :null => false

      t.timestamps
    end
  end
end
