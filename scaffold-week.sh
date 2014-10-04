#!/bin/bash
rails generate scaffold Week \
    iteration:integer \
    content:text \
    c1:date \
    c2:date \
    c3:date \
    c4:date \
    note:text