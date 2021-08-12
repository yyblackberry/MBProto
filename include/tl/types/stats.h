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

#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class BroadcastStats : public TLObject
{
private:
    int __id = 0xbdf78394;

public:
    TLObject period;
    TLObject followers;
    TLObject views_per_post;
    TLObject shares_per_post;
    TLObject enabled_notifications;
    TLObject growth_graph;
    TLObject followers_graph;
    TLObject mute_graph;
    TLObject top_hours_graph;
    TLObject interactions_graph;
    TLObject iv_interactions_graph;
    TLObject views_by_source_graph;
    TLObject new_followers_by_source_graph;
    TLObject languages_graph;
    std::vector<TLObject> recent_message_interactions;
    BroadcastStats(TLObject period_, TLObject followers_, TLObject views_per_post_, TLObject shares_per_post_, TLObject enabled_notifications_, TLObject growth_graph_, TLObject followers_graph_, TLObject mute_graph_, TLObject top_hours_graph_, TLObject interactions_graph_, TLObject iv_interactions_graph_, TLObject views_by_source_graph_, TLObject new_followers_by_source_graph_, TLObject languages_graph_, std::vector<TLObject> recent_message_interactions_);
    static BroadcastStats read(Reader reader);
    std::string write();
};

class MegagroupStats : public TLObject
{
private:
    int __id = 0xef7ff916;

public:
    TLObject period;
    TLObject members;
    TLObject messages;
    TLObject viewers;
    TLObject posters;
    TLObject growth_graph;
    TLObject members_graph;
    TLObject new_members_by_source_graph;
    TLObject languages_graph;
    TLObject messages_graph;
    TLObject actions_graph;
    TLObject top_hours_graph;
    TLObject weekdays_graph;
    std::vector<TLObject> top_posters;
    std::vector<TLObject> top_admins;
    std::vector<TLObject> top_inviters;
    std::vector<TLObject> users;
    MegagroupStats(TLObject period_, TLObject members_, TLObject messages_, TLObject viewers_, TLObject posters_, TLObject growth_graph_, TLObject members_graph_, TLObject new_members_by_source_graph_, TLObject languages_graph_, TLObject messages_graph_, TLObject actions_graph_, TLObject top_hours_graph_, TLObject weekdays_graph_, std::vector<TLObject> top_posters_, std::vector<TLObject> top_admins_, std::vector<TLObject> top_inviters_, std::vector<TLObject> users_);
    static MegagroupStats read(Reader reader);
    std::string write();
};

class MessageStats : public TLObject
{
private:
    int __id = 0x8999f295;

public:
    TLObject views_graph;
    MessageStats(TLObject views_graph_);
    static MessageStats read(Reader reader);
    std::string write();
};
