#!/bin/bash

MAIN_URL_PATH="https://music.163.com"
MAIN_HTML_PATH="../html/163"
MAIN_DATA_PATH="../data/163"
LOG_PATH="../log/163.log"
MAIN_HTML="${MAIN_DATA_PATH}/main.html"

function get_singer_list () {
	#<li><a hidefocus="true" data-module="artist" href="/discover/artist"><em>歌手</em></a></li>
	tmp=`cat ${MAIN_HTML} | egrep -o ".*href\=.*歌手" | awk -F '"' '{print $6}'`
	singer_list_url=${MAIN_URL_PATH}${tmp}

	local singer_list_path=${MAIN_HTML_PATH}/singer_list.html
	wget ${singer_list_url} -O ${singer_list_path} -o ${LOG_PATH}
	
}


function main() {
    wget $MAIN_URL_PATH -O ${MAIN_HTML} -o ${LOG_PATH}

    get_singer_list
}

main
