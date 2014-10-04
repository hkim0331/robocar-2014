require 'test_helper'

class IcomesControllerTest < ActionController::TestCase
  setup do
    @icome = icomes(:one)
  end

  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:icomes)
  end

  test "should get new" do
    get :new
    assert_response :success
  end

  test "should create icome" do
    assert_difference('Icome.count') do
      post :create, icome: { attend_at: @icome.attend_at, sid: @icome.sid }
    end

    assert_redirected_to icome_path(assigns(:icome))
  end

  test "should show icome" do
    get :show, id: @icome
    assert_response :success
  end

  test "should get edit" do
    get :edit, id: @icome
    assert_response :success
  end

  test "should update icome" do
    put :update, id: @icome, icome: { attend_at: @icome.attend_at, sid: @icome.sid }
    assert_redirected_to icome_path(assigns(:icome))
  end

  test "should destroy icome" do
    assert_difference('Icome.count', -1) do
      delete :destroy, id: @icome
    end

    assert_redirected_to icomes_path
  end
end
