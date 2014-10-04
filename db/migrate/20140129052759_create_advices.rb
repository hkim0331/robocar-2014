class CreateAdvices < ActiveRecord::Migration
  def change
    create_table :advices do |t|
      t.text :body

      t.timestamps
    end
  end
end
