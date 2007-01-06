/* gobby - A GTKmm driven libobby client
 * Copyright (C) 2005 0x539 dev group
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _GOBBY_CHAT_HPP_
#define _GOBBY_CHAT_HPP_

#include <gtkmm/box.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <obby/user.hpp>
#include <obby/local_document_info.hpp>
#include <obby/local_buffer.hpp>
#include "preferences.hpp"
#include "historyentry.hpp"
#include "logview.hpp"

namespace Gobby
{

class Chat: public Gtk::VBox
{
public:
	Chat();
	virtual ~Chat();

//	signal_chat_type chat_event() const;

	// Calls from the window
	void obby_start(obby::local_buffer& buf);
	void obby_end();
	void obby_user_join(const obby::user& user);
	void obby_user_part(const obby::user& user);
	void obby_document_insert(obby::local_document_info& document);
	void obby_document_remove(obby::local_document_info& document);

	//void obby_message(const obby::user& user, const Glib::ustring& message);
	//void obby_server_message(const Glib::ustring& message);
protected:
	//void add_line(const obby::user& user, const Glib::ustring& message);
	void on_chat();

	void on_message(const obby::chat::message& message);
	void on_user_message(const obby::chat::user_message& message);
	void on_server_message(const obby::chat::server_message& message);
	void on_system_message(const obby::chat::system_message& message);

	void send_line(const std::string& line);
	void recv_user_line(const std::string& line,
	                    const obby::chat::user_message& message);
	void recv_server_line(const std::string& line,
	                      const obby::chat::server_message& message);
	void recv_system_line(const std::string& line,
	                      const obby::chat::system_message& message);

	obby::local_buffer* m_buffer;

//	signal_chat_type m_signal_chat;

	Gtk::Image m_img_btn;
	Gtk::HBox m_box_chat;
	Gtk::ScrolledWindow m_wnd_chat;
	LogView m_log_chat;
	HistoryEntry m_ent_chat;
	Gtk::Button m_btn_chat;
};

}
	
#endif // _GOBBY_CHAT_HPP_
