#pragma once




#include <thread>
#include <mutex>
#include <string>
#include <functional>
#include <memory>


#include "common.h"
#include "util.h"

using std::string;
//using std::vector;
using std::thread;
using std::shared_ptr;
using std::thread;
using std::mutex;
using std::make_shared;
using std::bind;


enum class TLoglevel {
	loglevel_always,
	loglevel_fatal,
	loglevel_error,
	loglevel_warning,
	loglevel_debug,
	loglevel_info,
	loglevel_max
};

enum class LogColors {
	log_color_white				= FOREGROUND_RED	| FOREGROUND_BLUE		| FOREGROUND_GREEN		| FOREGROUND_INTENSITY,
	log_color_red				= FOREGROUND_RED,
	log_color_green				= FOREGROUND_GREEN,
	log_color_blue				= FOREGROUND_BLUE,
	log_color_yellow			= FOREGROUND_RED	| FOREGROUND_GREEN,
	log_color_purple			= FOREGROUND_RED	| FOREGROUND_BLUE,
	log_color_cyan				= FOREGROUND_GREEN	| FOREGROUND_BLUE,
	log_color_white_intensity	= FOREGROUND_RED	| FOREGROUND_BLUE		| FOREGROUND_GREEN		| FOREGROUND_INTENSITY,
	log_color_red_intensity		= FOREGROUND_RED	| FOREGROUND_INTENSITY,
	log_color_green_intensity	= FOREGROUND_GREEN	| FOREGROUND_INTENSITY,
	log_color_blue_intensity	= FOREGROUND_BLUE	| FOREGROUND_INTENSITY,
	log_color_yellow_intensity	= FOREGROUND_RED	| FOREGROUND_GREEN		| FOREGROUND_INTENSITY,
	log_color_purple_intensity	= FOREGROUND_RED	| FOREGROUND_BLUE		| FOREGROUND_INTENSITY,
	log_color_cyan_intensity	= FOREGROUND_GREEN	| FOREGROUND_BLUE		| FOREGROUND_INTENSITY
};