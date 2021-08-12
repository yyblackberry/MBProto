/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "tl/types/stats.h"

BroadcastStats::BroadcastStats(TLObject period_, TLObject followers_, TLObject views_per_post_, TLObject shares_per_post_, TLObject enabled_notifications_, TLObject growth_graph_, TLObject followers_graph_, TLObject mute_graph_, TLObject top_hours_graph_, TLObject interactions_graph_, TLObject iv_interactions_graph_, TLObject views_by_source_graph_, TLObject new_followers_by_source_graph_, TLObject languages_graph_, std::vector<TLObject> recent_message_interactions_) {}

BroadcastStats BroadcastStats::read(Reader reader)
{
    TLObject period_ = std::get<TLObject>(TLObject::read(reader));
    TLObject followers_ = std::get<TLObject>(TLObject::read(reader));
    TLObject views_per_post_ = std::get<TLObject>(TLObject::read(reader));
    TLObject shares_per_post_ = std::get<TLObject>(TLObject::read(reader));
    TLObject enabled_notifications_ = std::get<TLObject>(TLObject::read(reader));
    TLObject growth_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject followers_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject mute_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject top_hours_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject interactions_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject iv_interactions_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject views_by_source_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_followers_by_source_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject languages_graph_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> recent_message_interactions_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return BroadcastStats(period_, followers_, views_per_post_, shares_per_post_, enabled_notifications_, growth_graph_, followers_graph_, mute_graph_, top_hours_graph_, interactions_graph_, iv_interactions_graph_, views_by_source_graph_, new_followers_by_source_graph_, languages_graph_, recent_message_interactions_);
}

std::string BroadcastStats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += period.write();
    buffer += followers.write();
    buffer += views_per_post.write();
    buffer += shares_per_post.write();
    buffer += enabled_notifications.write();
    buffer += growth_graph.write();
    buffer += followers_graph.write();
    buffer += mute_graph.write();
    buffer += top_hours_graph.write();
    buffer += interactions_graph.write();
    buffer += iv_interactions_graph.write();
    buffer += views_by_source_graph.write();
    buffer += new_followers_by_source_graph.write();
    buffer += languages_graph.write();
    buffer += Vector<TLObject>::write(recent_message_interactions);
    return buffer;
}

MegagroupStats::MegagroupStats(TLObject period_, TLObject members_, TLObject messages_, TLObject viewers_, TLObject posters_, TLObject growth_graph_, TLObject members_graph_, TLObject new_members_by_source_graph_, TLObject languages_graph_, TLObject messages_graph_, TLObject actions_graph_, TLObject top_hours_graph_, TLObject weekdays_graph_, std::vector<TLObject> top_posters_, std::vector<TLObject> top_admins_, std::vector<TLObject> top_inviters_, std::vector<TLObject> users_) {}

MegagroupStats MegagroupStats::read(Reader reader)
{
    TLObject period_ = std::get<TLObject>(TLObject::read(reader));
    TLObject members_ = std::get<TLObject>(TLObject::read(reader));
    TLObject messages_ = std::get<TLObject>(TLObject::read(reader));
    TLObject viewers_ = std::get<TLObject>(TLObject::read(reader));
    TLObject posters_ = std::get<TLObject>(TLObject::read(reader));
    TLObject growth_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject members_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_members_by_source_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject languages_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject messages_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject actions_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject top_hours_graph_ = std::get<TLObject>(TLObject::read(reader));
    TLObject weekdays_graph_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> top_posters_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> top_admins_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> top_inviters_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return MegagroupStats(period_, members_, messages_, viewers_, posters_, growth_graph_, members_graph_, new_members_by_source_graph_, languages_graph_, messages_graph_, actions_graph_, top_hours_graph_, weekdays_graph_, top_posters_, top_admins_, top_inviters_, users_);
}

std::string MegagroupStats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += period.write();
    buffer += members.write();
    buffer += messages.write();
    buffer += viewers.write();
    buffer += posters.write();
    buffer += growth_graph.write();
    buffer += members_graph.write();
    buffer += new_members_by_source_graph.write();
    buffer += languages_graph.write();
    buffer += messages_graph.write();
    buffer += actions_graph.write();
    buffer += top_hours_graph.write();
    buffer += weekdays_graph.write();
    buffer += Vector<TLObject>::write(top_posters);
    buffer += Vector<TLObject>::write(top_admins);
    buffer += Vector<TLObject>::write(top_inviters);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

MessageStats::MessageStats(TLObject views_graph_) {}

MessageStats MessageStats::read(Reader reader)
{
    TLObject views_graph_ = std::get<TLObject>(TLObject::read(reader));
    return MessageStats(views_graph_);
}

std::string MessageStats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += views_graph.write();
    return buffer;
}
