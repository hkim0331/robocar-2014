#!/bin/bash
rails generate scaffold Lent \
    car_id:integer \
    condition:integer \
    lent_on:date \
    willback_on:date \
    back_on:date \
    sid:string \
    contact:string \
    note:text