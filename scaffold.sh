#!/bin/bash
rails generate scaffold Student \
    name:string \
    sid:string \
    uid:string \
    email:string \
    password:string \
    group_id:integer

rails generate scaffold Group \
    name:string \
    members:string \
    car_id:integer

rails generate scaffold Car \
    status:integer \
    lent_on:date \
    will_back:date



