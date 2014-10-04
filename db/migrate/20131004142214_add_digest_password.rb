class AddDigestPassword < ActiveRecord::Migration
  def change
    add_column :students, :password_digest, :string
    remove_column :students, :password
  end
end
