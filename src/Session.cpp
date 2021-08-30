/* Copyright (c) 2021 Mattia Lorenzo Chiabrando
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Session.h"

Session::Session(std::string storage_name, const int api_id, const std::string api_key, datacenter_t dc_id, const int port, const bool use_ipv6, transport_t transport_id) : __storage(storage_name)
{
    switch (transport_id)
    {
    case INTERMEDIATE:
        __transport = std::unique_ptr<Transport>(new TCP::Intermediate(dc_id, port, use_ipv6));
        break;

    case PADDED_INTERMEDIATE:
        __transport = std::unique_ptr<Transport>(new TCP::PaddedIntermediate(dc_id, port, use_ipv6));
        break;

    case FULL:
        __transport = std::unique_ptr<Transport>(new TCP::Full(dc_id, port, use_ipv6));
        break;

    default:
        __transport = std::unique_ptr<Transport>(new TCP::Abridged(dc_id, port, use_ipv6));
        break;
    }
};

void Session::start()
{
    if (__is_started)
        throw std::runtime_error("The session has already been started");
    __storage.start();
    __transport->start();
    __is_started = true;
}

void Session::stop()
{
    if (!__is_started)
        throw std::runtime_error("The session has not been started yet");
    __storage.stop();
    __transport->stop();
    __is_started = false;
}

Session::~Session()
{
    if (__is_started)
        stop();
}
