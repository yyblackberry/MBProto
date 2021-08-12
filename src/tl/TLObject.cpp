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

#include "tl/TLObject.h"
#include "tl/types/base.h"
#include "tl/functions/base.h"
#include "tl/functions/help.h"
#include "tl/types/storage.h"
#include "tl/types/auth.h"
#include "tl/types/contacts.h"
#include "tl/types/messages.h"
#include "tl/types/updates.h"
#include "tl/types/photos.h"
#include "tl/types/upload.h"
#include "tl/types/help.h"
#include "tl/types/account.h"
#include "tl/types/channels.h"
#include "tl/types/payments.h"
#include "tl/types/phone.h"
#include "tl/types/stats.h"
#include "tl/types/stickers.h"
#include "tl/functions/auth.h"
#include "tl/functions/account.h"
#include "tl/functions/users.h"
#include "tl/functions/contacts.h"
#include "tl/functions/messages.h"
#include "tl/functions/updates.h"
#include "tl/functions/photos.h"
#include "tl/functions/upload.h"
#include "tl/functions/channels.h"
#include "tl/functions/bots.h"
#include "tl/functions/payments.h"
#include "tl/functions/stickers.h"
#include "tl/functions/phone.h"
#include "tl/functions/langpack.h"
#include "tl/functions/folders.h"
#include "tl/functions/stats.h"

std::variant<TLObject, std::vector<TLObject>> TLObject::read(Reader reader)
{
    int id = unpackInt(reader.read(4));

    if (id == 0x05162463)
        return ResPQ::read(reader);
    else if (id == 0xa9f55f95)
        return PQInnerDataDc::read(reader);
    else if (id == 0x56fddf88)
        return PQInnerDataTempDc::read(reader);
    else if (id == 0x79cb045d)
        return ServerDHParamsFail::read(reader);
    else if (id == 0xd0e8075c)
        return ServerDHParamsOk::read(reader);
    else if (id == 0xb5890dba)
        return ServerDHInnerData::read(reader);
    else if (id == 0x6643b654)
        return ClientDHInnerData::read(reader);
    else if (id == 0x3bcbf734)
        return DhGenOk::read(reader);
    else if (id == 0x46dc1fb9)
        return DhGenRetry::read(reader);
    else if (id == 0xa69dae02)
        return DhGenFail::read(reader);
    else if (id == 0x2144ca19)
        return RpcError::read(reader);
    else if (id == 0x5e2ad36e)
        return RpcAnswerUnknown::read(reader);
    else if (id == 0xcd78e586)
        return RpcAnswerDroppedRunning::read(reader);
    else if (id == 0xa43ad8b7)
        return RpcAnswerDropped::read(reader);
    else if (id == 0x0949d9dc)
        return FutureSalt::read(reader);
    else if (id == 0xae500895)
        return FutureSalts::read(reader);
    else if (id == 0x347773c5)
        return Pong::read(reader);
    else if (id == 0xe22045fc)
        return DestroySessionOk::read(reader);
    else if (id == 0x62d350c9)
        return DestroySessionNone::read(reader);
    else if (id == 0x9ec20908)
        return NewSessionCreated::read(reader);
    else if (id == 0x3072cfa1)
        return GzipPacked::read(reader);
    else if (id == 0x62d6b459)
        return MsgsAck::read(reader);
    else if (id == 0xa7eff811)
        return BadMsgNotification::read(reader);
    else if (id == 0xedab447b)
        return BadServerSalt::read(reader);
    else if (id == 0x7d861a08)
        return MsgResendReq::read(reader);
    else if (id == 0xda69fb52)
        return MsgsStateReq::read(reader);
    else if (id == 0x04deb57d)
        return MsgsStateInfo::read(reader);
    else if (id == 0x8cc0d131)
        return MsgsAllInfo::read(reader);
    else if (id == 0x276d3ec6)
        return MsgDetailedInfo::read(reader);
    else if (id == 0x809db6df)
        return MsgNewDetailedInfo::read(reader);
    else if (id == 0xf660e1d4)
        return DestroyAuthKeyOk::read(reader);
    else if (id == 0x0a9f2259)
        return DestroyAuthKeyNone::read(reader);
    else if (id == 0xea109b13)
        return DestroyAuthKeyFail::read(reader);
    else if (id == 0xbe7e8ef1)
        return ReqPqMulti::read(reader);
    else if (id == 0xd712e4be)
        return ReqDHParams::read(reader);
    else if (id == 0xf5045f1f)
        return SetClientDHParams::read(reader);
    else if (id == 0x58e4a740)
        return RpcDropAnswer::read(reader);
    else if (id == 0xb921bd04)
        return GetFutureSalts::read(reader);
    else if (id == 0x7abe77ec)
        return Ping::read(reader);
    else if (id == 0xf3427b8c)
        return PingDelayDisconnect::read(reader);
    else if (id == 0xe7512126)
        return DestroySession::read(reader);
    else if (id == 0x9299359f)
        return HttpWait::read(reader);
    else if (id == 0xd1435160)
        return DestroyAuthKey::read(reader);
    else if (id == 0x1cb5c415)
        return Vector<TLObject>::read(reader);
    else if (id == 0xc4b9f9bb)
        return Error::read(reader);
    else if (id == 0xd433ad73)
        return IpPort::read(reader);
    else if (id == 0x37982646)
        return IpPortSecret::read(reader);
    else if (id == 0x4679b65f)
        return AccessPointRule::read(reader);
    else if (id == 0x5a592a6c)
        return ConfigSimple::read(reader);
    else if (id == 0x27d69997)
        return InputPeerPhotoFileLocationLegacy::read(reader);
    else if (id == 0xdbaeae9)
        return InputStickerSetThumbLegacy::read(reader);
    else if (id == 0x7f3b18ea)
        return InputPeerEmpty::read(reader);
    else if (id == 0x7da07ec9)
        return InputPeerSelf::read(reader);
    else if (id == 0x179be863)
        return InputPeerChat::read(reader);
    else if (id == 0x7b8e7de6)
        return InputPeerUser::read(reader);
    else if (id == 0x20adaef8)
        return InputPeerChannel::read(reader);
    else if (id == 0x17bae2e6)
        return InputPeerUserFromMessage::read(reader);
    else if (id == 0x9c95f7bb)
        return InputPeerChannelFromMessage::read(reader);
    else if (id == 0xb98886cf)
        return InputUserEmpty::read(reader);
    else if (id == 0xf7c1b13f)
        return InputUserSelf::read(reader);
    else if (id == 0xd8292816)
        return InputUser::read(reader);
    else if (id == 0x2d117597)
        return InputUserFromMessage::read(reader);
    else if (id == 0xf392b7f4)
        return InputPhoneContact::read(reader);
    else if (id == 0xf52ff27f)
        return InputFile::read(reader);
    else if (id == 0xfa4f0bb5)
        return InputFileBig::read(reader);
    else if (id == 0x9664f57f)
        return InputMediaEmpty::read(reader);
    else if (id == 0x1e287d04)
        return InputMediaUploadedPhoto::read(reader);
    else if (id == 0xb3ba0635)
        return InputMediaPhoto::read(reader);
    else if (id == 0xf9c44144)
        return InputMediaGeoPoint::read(reader);
    else if (id == 0xf8ab7dfb)
        return InputMediaContact::read(reader);
    else if (id == 0x5b38c6c1)
        return InputMediaUploadedDocument::read(reader);
    else if (id == 0x33473058)
        return InputMediaDocument::read(reader);
    else if (id == 0xc13d1c11)
        return InputMediaVenue::read(reader);
    else if (id == 0xe5bbfe1a)
        return InputMediaPhotoExternal::read(reader);
    else if (id == 0xfb52dc99)
        return InputMediaDocumentExternal::read(reader);
    else if (id == 0xd33f43f3)
        return InputMediaGame::read(reader);
    else if (id == 0xd9799874)
        return InputMediaInvoice::read(reader);
    else if (id == 0x971fa843)
        return InputMediaGeoLive::read(reader);
    else if (id == 0xf94e5f1)
        return InputMediaPoll::read(reader);
    else if (id == 0xe66fbf7b)
        return InputMediaDice::read(reader);
    else if (id == 0x1ca48f57)
        return InputChatPhotoEmpty::read(reader);
    else if (id == 0xc642724e)
        return InputChatUploadedPhoto::read(reader);
    else if (id == 0x8953ad37)
        return InputChatPhoto::read(reader);
    else if (id == 0xe4c123d6)
        return InputGeoPointEmpty::read(reader);
    else if (id == 0x48222faf)
        return InputGeoPoint::read(reader);
    else if (id == 0x1cd7bf0d)
        return InputPhotoEmpty::read(reader);
    else if (id == 0x3bb3b94a)
        return InputPhoto::read(reader);
    else if (id == 0xdfdaabe1)
        return InputFileLocation::read(reader);
    else if (id == 0xf5235d55)
        return InputEncryptedFileLocation::read(reader);
    else if (id == 0xbad07584)
        return InputDocumentFileLocation::read(reader);
    else if (id == 0xcbc7ee28)
        return InputSecureFileLocation::read(reader);
    else if (id == 0x29be5899)
        return InputTakeoutFileLocation::read(reader);
    else if (id == 0x40181ffe)
        return InputPhotoFileLocation::read(reader);
    else if (id == 0xd83466f3)
        return InputPhotoLegacyFileLocation::read(reader);
    else if (id == 0x37257e99)
        return InputPeerPhotoFileLocation::read(reader);
    else if (id == 0x9d84f3db)
        return InputStickerSetThumb::read(reader);
    else if (id == 0xbba51639)
        return InputGroupCallStream::read(reader);
    else if (id == 0x9db1bc6d)
        return PeerUser::read(reader);
    else if (id == 0xbad0e5bb)
        return PeerChat::read(reader);
    else if (id == 0xbddde532)
        return PeerChannel::read(reader);
    else if (id == 0xaa963b05)
        return FileUnknown::read(reader);
    else if (id == 0x40bc6f52)
        return FilePartial::read(reader);
    else if (id == 0x7efe0e)
        return FileJpeg::read(reader);
    else if (id == 0xcae1aadf)
        return FileGif::read(reader);
    else if (id == 0xa4f63c0)
        return FilePng::read(reader);
    else if (id == 0xae1e508d)
        return FilePdf::read(reader);
    else if (id == 0x4b09ebbc)
        return FileMov::read(reader);
    else if (id == 0x1081464c)
        return FileWebp::read(reader);
    else if (id == 0x200250ba)
        return UserEmpty::read(reader);
    else if (id == 0x938458c1)
        return User::read(reader);
    else if (id == 0x4f11bae1)
        return UserProfilePhotoEmpty::read(reader);
    else if (id == 0x82d1f706)
        return UserProfilePhoto::read(reader);
    else if (id == 0x9d05049)
        return UserStatusEmpty::read(reader);
    else if (id == 0xedb93949)
        return UserStatusOnline::read(reader);
    else if (id == 0x8c703f)
        return UserStatusOffline::read(reader);
    else if (id == 0xe26f42f1)
        return UserStatusRecently::read(reader);
    else if (id == 0x7bf09fc)
        return UserStatusLastWeek::read(reader);
    else if (id == 0x77ebc742)
        return UserStatusLastMonth::read(reader);
    else if (id == 0x9ba2d800)
        return ChatEmpty::read(reader);
    else if (id == 0x3bda1bde)
        return Chat::read(reader);
    else if (id == 0x7328bdb)
        return ChatForbidden::read(reader);
    else if (id == 0xd31a961e)
        return Channel::read(reader);
    else if (id == 0x289da732)
        return ChannelForbidden::read(reader);
    else if (id == 0x8a1e2983)
        return ChatFull::read(reader);
    else if (id == 0x548c3f93)
        return ChannelFull::read(reader);
    else if (id == 0xc8d7493e)
        return ChatParticipant::read(reader);
    else if (id == 0xda13538a)
        return ChatParticipantCreator::read(reader);
    else if (id == 0xe2d6e436)
        return ChatParticipantAdmin::read(reader);
    else if (id == 0xfc900c2b)
        return ChatParticipantsForbidden::read(reader);
    else if (id == 0x3f460fed)
        return ChatParticipants::read(reader);
    else if (id == 0x37c1011c)
        return ChatPhotoEmpty::read(reader);
    else if (id == 0x1c6e1c11)
        return ChatPhoto::read(reader);
    else if (id == 0x90a6ca84)
        return MessageEmpty::read(reader);
    else if (id == 0xbce383d2)
        return Message::read(reader);
    else if (id == 0x2b085862)
        return MessageService::read(reader);
    else if (id == 0x3ded6320)
        return MessageMediaEmpty::read(reader);
    else if (id == 0x695150d7)
        return MessageMediaPhoto::read(reader);
    else if (id == 0x56e0d474)
        return MessageMediaGeo::read(reader);
    else if (id == 0xcbf24940)
        return MessageMediaContact::read(reader);
    else if (id == 0x9f84f49e)
        return MessageMediaUnsupported::read(reader);
    else if (id == 0x9cb070d7)
        return MessageMediaDocument::read(reader);
    else if (id == 0xa32dd600)
        return MessageMediaWebPage::read(reader);
    else if (id == 0x2ec0533f)
        return MessageMediaVenue::read(reader);
    else if (id == 0xfdb19008)
        return MessageMediaGame::read(reader);
    else if (id == 0x84551347)
        return MessageMediaInvoice::read(reader);
    else if (id == 0xb940c666)
        return MessageMediaGeoLive::read(reader);
    else if (id == 0x4bd6e798)
        return MessageMediaPoll::read(reader);
    else if (id == 0x3f7ee58b)
        return MessageMediaDice::read(reader);
    else if (id == 0xb6aef7b0)
        return MessageActionEmpty::read(reader);
    else if (id == 0xa6638b9a)
        return MessageActionChatCreate::read(reader);
    else if (id == 0xb5a1ce5a)
        return MessageActionChatEditTitle::read(reader);
    else if (id == 0x7fcb13a8)
        return MessageActionChatEditPhoto::read(reader);
    else if (id == 0x95e3fbef)
        return MessageActionChatDeletePhoto::read(reader);
    else if (id == 0x488a7337)
        return MessageActionChatAddUser::read(reader);
    else if (id == 0xb2ae9b0c)
        return MessageActionChatDeleteUser::read(reader);
    else if (id == 0xf89cf5e8)
        return MessageActionChatJoinedByLink::read(reader);
    else if (id == 0x95d2ac92)
        return MessageActionChannelCreate::read(reader);
    else if (id == 0x51bdb021)
        return MessageActionChatMigrateTo::read(reader);
    else if (id == 0xb055eaee)
        return MessageActionChannelMigrateFrom::read(reader);
    else if (id == 0x94bd38ed)
        return MessageActionPinMessage::read(reader);
    else if (id == 0x9fbab604)
        return MessageActionHistoryClear::read(reader);
    else if (id == 0x92a72876)
        return MessageActionGameScore::read(reader);
    else if (id == 0x8f31b327)
        return MessageActionPaymentSentMe::read(reader);
    else if (id == 0x40699cd0)
        return MessageActionPaymentSent::read(reader);
    else if (id == 0x80e11a7f)
        return MessageActionPhoneCall::read(reader);
    else if (id == 0x4792929b)
        return MessageActionScreenshotTaken::read(reader);
    else if (id == 0xfae69f56)
        return MessageActionCustomAction::read(reader);
    else if (id == 0xabe9affe)
        return MessageActionBotAllowed::read(reader);
    else if (id == 0x1b287353)
        return MessageActionSecureValuesSentMe::read(reader);
    else if (id == 0xd95c6154)
        return MessageActionSecureValuesSent::read(reader);
    else if (id == 0xf3f25f76)
        return MessageActionContactSignUp::read(reader);
    else if (id == 0x98e0d697)
        return MessageActionGeoProximityReached::read(reader);
    else if (id == 0x7a0d7f42)
        return MessageActionGroupCall::read(reader);
    else if (id == 0x76b9f11a)
        return MessageActionInviteToGroupCall::read(reader);
    else if (id == 0xaa1afbfd)
        return MessageActionSetMessagesTTL::read(reader);
    else if (id == 0xb3a07661)
        return MessageActionGroupCallScheduled::read(reader);
    else if (id == 0x2c171f72)
        return Dialog::read(reader);
    else if (id == 0x71bd134c)
        return DialogFolder::read(reader);
    else if (id == 0x2331b22d)
        return PhotoEmpty::read(reader);
    else if (id == 0xfb197a65)
        return Photo::read(reader);
    else if (id == 0xe17e23c)
        return PhotoSizeEmpty::read(reader);
    else if (id == 0x75c78e60)
        return PhotoSize::read(reader);
    else if (id == 0x21e1ad6)
        return PhotoCachedSize::read(reader);
    else if (id == 0xe0b0bc2e)
        return PhotoStrippedSize::read(reader);
    else if (id == 0xfa3efb95)
        return PhotoSizeProgressive::read(reader);
    else if (id == 0xd8214d41)
        return PhotoPathSize::read(reader);
    else if (id == 0x1117dd5f)
        return GeoPointEmpty::read(reader);
    else if (id == 0xb2a2f663)
        return GeoPoint::read(reader);
    else if (id == 0x5e002502)
        return SentCode::read(reader);
    else if (id == 0xcd050916)
        return Authorization::read(reader);
    else if (id == 0x44747e9a)
        return AuthorizationSignUpRequired::read(reader);
    else if (id == 0xdf969c2d)
        return ExportedAuthorization::read(reader);
    else if (id == 0xb8bc5b0c)
        return InputNotifyPeer::read(reader);
    else if (id == 0x193b4417)
        return InputNotifyUsers::read(reader);
    else if (id == 0x4a95e84e)
        return InputNotifyChats::read(reader);
    else if (id == 0xb1db7c7e)
        return InputNotifyBroadcasts::read(reader);
    else if (id == 0x9c3d198e)
        return InputPeerNotifySettings::read(reader);
    else if (id == 0xaf509d20)
        return PeerNotifySettings::read(reader);
    else if (id == 0x733f2961)
        return PeerSettings::read(reader);
    else if (id == 0xa437c3ed)
        return WallPaper::read(reader);
    else if (id == 0xe0804116)
        return WallPaperNoFile::read(reader);
    else if (id == 0x58dbcab8)
        return InputReportReasonSpam::read(reader);
    else if (id == 0x1e22c78d)
        return InputReportReasonViolence::read(reader);
    else if (id == 0x2e59d922)
        return InputReportReasonPornography::read(reader);
    else if (id == 0xadf44ee3)
        return InputReportReasonChildAbuse::read(reader);
    else if (id == 0xc1e4a2b1)
        return InputReportReasonOther::read(reader);
    else if (id == 0x9b89f93a)
        return InputReportReasonCopyright::read(reader);
    else if (id == 0xdbd4feed)
        return InputReportReasonGeoIrrelevant::read(reader);
    else if (id == 0xf5ddd6e7)
        return InputReportReasonFake::read(reader);
    else if (id == 0x139a9a77)
        return UserFull::read(reader);
    else if (id == 0xf911c994)
        return Contact::read(reader);
    else if (id == 0xd0028438)
        return ImportedContact::read(reader);
    else if (id == 0xd3680c61)
        return ContactStatus::read(reader);
    else if (id == 0xb74ba9d2)
        return ContactsNotModified::read(reader);
    else if (id == 0xeae87e42)
        return Contacts::read(reader);
    else if (id == 0x77d01c3b)
        return ImportedContacts::read(reader);
    else if (id == 0xade1591)
        return Blocked::read(reader);
    else if (id == 0xe1664194)
        return BlockedSlice::read(reader);
    else if (id == 0x15ba6c40)
        return Dialogs::read(reader);
    else if (id == 0x71e094f3)
        return DialogsSlice::read(reader);
    else if (id == 0xf0e3e596)
        return DialogsNotModified::read(reader);
    else if (id == 0x8c718e87)
        return Messages::read(reader);
    else if (id == 0x3a54685e)
        return MessagesSlice::read(reader);
    else if (id == 0x64479808)
        return ChannelMessages::read(reader);
    else if (id == 0x74535f21)
        return MessagesNotModified::read(reader);
    else if (id == 0x64ff9fd5)
        return Chats::read(reader);
    else if (id == 0x9cd81144)
        return ChatsSlice::read(reader);
    else if (id == 0xe5d7d19c)
        return ChatFull::read(reader);
    else if (id == 0xb45c69d1)
        return AffectedHistory::read(reader);
    else if (id == 0x57e2f66c)
        return InputMessagesFilterEmpty::read(reader);
    else if (id == 0x9609a51c)
        return InputMessagesFilterPhotos::read(reader);
    else if (id == 0x9fc00e65)
        return InputMessagesFilterVideo::read(reader);
    else if (id == 0x56e9f0e4)
        return InputMessagesFilterPhotoVideo::read(reader);
    else if (id == 0x9eddf188)
        return InputMessagesFilterDocument::read(reader);
    else if (id == 0x7ef0dd87)
        return InputMessagesFilterUrl::read(reader);
    else if (id == 0xffc86587)
        return InputMessagesFilterGif::read(reader);
    else if (id == 0x50f5c392)
        return InputMessagesFilterVoice::read(reader);
    else if (id == 0x3751b49e)
        return InputMessagesFilterMusic::read(reader);
    else if (id == 0x3a20ecb8)
        return InputMessagesFilterChatPhotos::read(reader);
    else if (id == 0x80c99768)
        return InputMessagesFilterPhoneCalls::read(reader);
    else if (id == 0x7a7c17a4)
        return InputMessagesFilterRoundVoice::read(reader);
    else if (id == 0xb549da53)
        return InputMessagesFilterRoundVideo::read(reader);
    else if (id == 0xc1f8e69a)
        return InputMessagesFilterMyMentions::read(reader);
    else if (id == 0xe7026d0d)
        return InputMessagesFilterGeo::read(reader);
    else if (id == 0xe062db83)
        return InputMessagesFilterContacts::read(reader);
    else if (id == 0x1bb00451)
        return InputMessagesFilterPinned::read(reader);
    else if (id == 0x1f2b0afd)
        return UpdateNewMessage::read(reader);
    else if (id == 0x4e90bfd6)
        return UpdateMessageID::read(reader);
    else if (id == 0xa20db0e5)
        return UpdateDeleteMessages::read(reader);
    else if (id == 0x5c486927)
        return UpdateUserTyping::read(reader);
    else if (id == 0x86cadb6c)
        return UpdateChatUserTyping::read(reader);
    else if (id == 0x7761198)
        return UpdateChatParticipants::read(reader);
    else if (id == 0x1bfbd823)
        return UpdateUserStatus::read(reader);
    else if (id == 0xa7332b73)
        return UpdateUserName::read(reader);
    else if (id == 0x95313b0c)
        return UpdateUserPhoto::read(reader);
    else if (id == 0x12bcbd9a)
        return UpdateNewEncryptedMessage::read(reader);
    else if (id == 0x1710f156)
        return UpdateEncryptedChatTyping::read(reader);
    else if (id == 0xb4a2e88d)
        return UpdateEncryption::read(reader);
    else if (id == 0x38fe25b7)
        return UpdateEncryptedMessagesRead::read(reader);
    else if (id == 0xea4b0e5c)
        return UpdateChatParticipantAdd::read(reader);
    else if (id == 0x6e5f8c22)
        return UpdateChatParticipantDelete::read(reader);
    else if (id == 0x8e5e9873)
        return UpdateDcOptions::read(reader);
    else if (id == 0xbec268ef)
        return UpdateNotifySettings::read(reader);
    else if (id == 0xebe46819)
        return UpdateServiceNotification::read(reader);
    else if (id == 0xee3b272a)
        return UpdatePrivacy::read(reader);
    else if (id == 0x12b9417b)
        return UpdateUserPhone::read(reader);
    else if (id == 0x9c974fdf)
        return UpdateReadHistoryInbox::read(reader);
    else if (id == 0x2f2f21bf)
        return UpdateReadHistoryOutbox::read(reader);
    else if (id == 0x7f891213)
        return UpdateWebPage::read(reader);
    else if (id == 0x68c13933)
        return UpdateReadMessagesContents::read(reader);
    else if (id == 0xeb0467fb)
        return UpdateChannelTooLong::read(reader);
    else if (id == 0xb6d45656)
        return UpdateChannel::read(reader);
    else if (id == 0x62ba04d9)
        return UpdateNewChannelMessage::read(reader);
    else if (id == 0x330b5424)
        return UpdateReadChannelInbox::read(reader);
    else if (id == 0xc37521c9)
        return UpdateDeleteChannelMessages::read(reader);
    else if (id == 0x98a12b4b)
        return UpdateChannelMessageViews::read(reader);
    else if (id == 0xb6901959)
        return UpdateChatParticipantAdmin::read(reader);
    else if (id == 0x688a30aa)
        return UpdateNewStickerSet::read(reader);
    else if (id == 0xbb2d201)
        return UpdateStickerSetsOrder::read(reader);
    else if (id == 0x43ae3dec)
        return UpdateStickerSets::read(reader);
    else if (id == 0x9375341e)
        return UpdateSavedGifs::read(reader);
    else if (id == 0x3f2038db)
        return UpdateBotInlineQuery::read(reader);
    else if (id == 0xe48f964)
        return UpdateBotInlineSend::read(reader);
    else if (id == 0x1b3f4df7)
        return UpdateEditChannelMessage::read(reader);
    else if (id == 0xe73547e1)
        return UpdateBotCallbackQuery::read(reader);
    else if (id == 0xe40370a3)
        return UpdateEditMessage::read(reader);
    else if (id == 0xf9d27a5a)
        return UpdateInlineBotCallbackQuery::read(reader);
    else if (id == 0x25d6c9c7)
        return UpdateReadChannelOutbox::read(reader);
    else if (id == 0xee2bb969)
        return UpdateDraftMessage::read(reader);
    else if (id == 0x571d2742)
        return UpdateReadFeaturedStickers::read(reader);
    else if (id == 0x9a422c20)
        return UpdateRecentStickers::read(reader);
    else if (id == 0xa229dd06)
        return UpdateConfig::read(reader);
    else if (id == 0x3354678f)
        return UpdatePtsChanged::read(reader);
    else if (id == 0x40771900)
        return UpdateChannelWebPage::read(reader);
    else if (id == 0x6e6fe51c)
        return UpdateDialogPinned::read(reader);
    else if (id == 0xfa0f3ca2)
        return UpdatePinnedDialogs::read(reader);
    else if (id == 0x8317c0c3)
        return UpdateBotWebhookJSON::read(reader);
    else if (id == 0x9b9240a6)
        return UpdateBotWebhookJSONQuery::read(reader);
    else if (id == 0xe0cdc940)
        return UpdateBotShippingQuery::read(reader);
    else if (id == 0x5d2f3aa9)
        return UpdateBotPrecheckoutQuery::read(reader);
    else if (id == 0xab0f6b1e)
        return UpdatePhoneCall::read(reader);
    else if (id == 0x46560264)
        return UpdateLangPackTooLong::read(reader);
    else if (id == 0x56022f4d)
        return UpdateLangPack::read(reader);
    else if (id == 0xe511996d)
        return UpdateFavedStickers::read(reader);
    else if (id == 0x89893b45)
        return UpdateChannelReadMessagesContents::read(reader);
    else if (id == 0x7084a7be)
        return UpdateContactsReset::read(reader);
    else if (id == 0x70db6837)
        return UpdateChannelAvailableMessages::read(reader);
    else if (id == 0xe16459c3)
        return UpdateDialogUnreadMark::read(reader);
    else if (id == 0xaca1657b)
        return UpdateMessagePoll::read(reader);
    else if (id == 0x54c01850)
        return UpdateChatDefaultBannedRights::read(reader);
    else if (id == 0x19360dc0)
        return UpdateFolderPeers::read(reader);
    else if (id == 0x6a7e7366)
        return UpdatePeerSettings::read(reader);
    else if (id == 0xb4afcfb0)
        return UpdatePeerLocated::read(reader);
    else if (id == 0x39a51dfb)
        return UpdateNewScheduledMessage::read(reader);
    else if (id == 0x90866cee)
        return UpdateDeleteScheduledMessages::read(reader);
    else if (id == 0x8216fba3)
        return UpdateTheme::read(reader);
    else if (id == 0x871fb939)
        return UpdateGeoLiveViewed::read(reader);
    else if (id == 0x564fe691)
        return UpdateLoginToken::read(reader);
    else if (id == 0x37f69f0b)
        return UpdateMessagePollVote::read(reader);
    else if (id == 0x26ffde7d)
        return UpdateDialogFilter::read(reader);
    else if (id == 0xa5d72105)
        return UpdateDialogFilterOrder::read(reader);
    else if (id == 0x3504914f)
        return UpdateDialogFilters::read(reader);
    else if (id == 0x2661bf09)
        return UpdatePhoneCallSignalingData::read(reader);
    else if (id == 0x6e8a84df)
        return UpdateChannelMessageForwards::read(reader);
    else if (id == 0x1cc7de54)
        return UpdateReadChannelDiscussionInbox::read(reader);
    else if (id == 0x4638a26c)
        return UpdateReadChannelDiscussionOutbox::read(reader);
    else if (id == 0x246a4b22)
        return UpdatePeerBlocked::read(reader);
    else if (id == 0x6b171718)
        return UpdateChannelUserTyping::read(reader);
    else if (id == 0xed85eab5)
        return UpdatePinnedMessages::read(reader);
    else if (id == 0x8588878b)
        return UpdatePinnedChannelMessages::read(reader);
    else if (id == 0x1330a196)
        return UpdateChat::read(reader);
    else if (id == 0xf2ebdb4e)
        return UpdateGroupCallParticipants::read(reader);
    else if (id == 0xa45eb99b)
        return UpdateGroupCall::read(reader);
    else if (id == 0xbb9bb9a5)
        return UpdatePeerHistoryTTL::read(reader);
    else if (id == 0xf3b3781f)
        return UpdateChatParticipant::read(reader);
    else if (id == 0x7fecb1ec)
        return UpdateChannelParticipant::read(reader);
    else if (id == 0x7f9488a)
        return UpdateBotStopped::read(reader);
    else if (id == 0xb783982)
        return UpdateGroupCallConnection::read(reader);
    else if (id == 0xa56c2a3e)
        return State::read(reader);
    else if (id == 0x5d75a138)
        return DifferenceEmpty::read(reader);
    else if (id == 0xf49ca0)
        return Difference::read(reader);
    else if (id == 0xa8fb1981)
        return DifferenceSlice::read(reader);
    else if (id == 0x4afe8f6d)
        return DifferenceTooLong::read(reader);
    else if (id == 0xe317af7e)
        return UpdatesTooLong::read(reader);
    else if (id == 0xfaeff833)
        return UpdateShortMessage::read(reader);
    else if (id == 0x1157b858)
        return UpdateShortChatMessage::read(reader);
    else if (id == 0x78d4dec1)
        return UpdateShort::read(reader);
    else if (id == 0x725b04c3)
        return UpdatesCombined::read(reader);
    else if (id == 0x74ae4240)
        return Updates::read(reader);
    else if (id == 0x9015e101)
        return UpdateShortSentMessage::read(reader);
    else if (id == 0x8dca6aa5)
        return Photos::read(reader);
    else if (id == 0x15051f54)
        return PhotosSlice::read(reader);
    else if (id == 0x20212ca8)
        return Photo::read(reader);
    else if (id == 0x96a18d5)
        return File::read(reader);
    else if (id == 0xf18cda44)
        return FileCdnRedirect::read(reader);
    else if (id == 0x18b7a10d)
        return DcOption::read(reader);
    else if (id == 0x330b4067)
        return Config::read(reader);
    else if (id == 0x8e1a1775)
        return NearestDc::read(reader);
    else if (id == 0xccbbce30)
        return AppUpdate::read(reader);
    else if (id == 0xc45a6536)
        return NoAppUpdate::read(reader);
    else if (id == 0x18cb9f78)
        return InviteText::read(reader);
    else if (id == 0xab7ec0a0)
        return EncryptedChatEmpty::read(reader);
    else if (id == 0x3bf703dc)
        return EncryptedChatWaiting::read(reader);
    else if (id == 0x62718a82)
        return EncryptedChatRequested::read(reader);
    else if (id == 0xfa56ce36)
        return EncryptedChat::read(reader);
    else if (id == 0x1e1c7c45)
        return EncryptedChatDiscarded::read(reader);
    else if (id == 0xf141b5e1)
        return InputEncryptedChat::read(reader);
    else if (id == 0xc21f497e)
        return EncryptedFileEmpty::read(reader);
    else if (id == 0x4a70994c)
        return EncryptedFile::read(reader);
    else if (id == 0x1837c364)
        return InputEncryptedFileEmpty::read(reader);
    else if (id == 0x64bd0306)
        return InputEncryptedFileUploaded::read(reader);
    else if (id == 0x5a17b5e5)
        return InputEncryptedFile::read(reader);
    else if (id == 0x2dc173c8)
        return InputEncryptedFileBigUploaded::read(reader);
    else if (id == 0xed18c118)
        return EncryptedMessage::read(reader);
    else if (id == 0x23734b06)
        return EncryptedMessageService::read(reader);
    else if (id == 0xc0e24635)
        return DhConfigNotModified::read(reader);
    else if (id == 0x2c221edd)
        return DhConfig::read(reader);
    else if (id == 0x560f8935)
        return SentEncryptedMessage::read(reader);
    else if (id == 0x9493ff32)
        return SentEncryptedFile::read(reader);
    else if (id == 0x72f0eaae)
        return InputDocumentEmpty::read(reader);
    else if (id == 0x1abfb575)
        return InputDocument::read(reader);
    else if (id == 0x36f8c871)
        return DocumentEmpty::read(reader);
    else if (id == 0x1e87342b)
        return Document::read(reader);
    else if (id == 0x17c6b5f6)
        return Support::read(reader);
    else if (id == 0x9fd40bd8)
        return NotifyPeer::read(reader);
    else if (id == 0xb4c83b4c)
        return NotifyUsers::read(reader);
    else if (id == 0xc007cec3)
        return NotifyChats::read(reader);
    else if (id == 0xd612e8ef)
        return NotifyBroadcasts::read(reader);
    else if (id == 0x16bf744e)
        return SendMessageTypingAction::read(reader);
    else if (id == 0xfd5ec8f5)
        return SendMessageCancelAction::read(reader);
    else if (id == 0xa187d66f)
        return SendMessageRecordVideoAction::read(reader);
    else if (id == 0xe9763aec)
        return SendMessageUploadVideoAction::read(reader);
    else if (id == 0xd52f73f7)
        return SendMessageRecordAudioAction::read(reader);
    else if (id == 0xf351d7ab)
        return SendMessageUploadAudioAction::read(reader);
    else if (id == 0xd1d34a26)
        return SendMessageUploadPhotoAction::read(reader);
    else if (id == 0xaa0cd9e4)
        return SendMessageUploadDocumentAction::read(reader);
    else if (id == 0x176f8ba1)
        return SendMessageGeoLocationAction::read(reader);
    else if (id == 0x628cbc6f)
        return SendMessageChooseContactAction::read(reader);
    else if (id == 0xdd6a8f48)
        return SendMessageGamePlayAction::read(reader);
    else if (id == 0x88f27fbc)
        return SendMessageRecordRoundAction::read(reader);
    else if (id == 0x243e1c66)
        return SendMessageUploadRoundAction::read(reader);
    else if (id == 0xd92c2285)
        return SpeakingInGroupCallAction::read(reader);
    else if (id == 0xdbda9246)
        return SendMessageHistoryImportAction::read(reader);
    else if (id == 0xb3134d9d)
        return Found::read(reader);
    else if (id == 0x4f96cb18)
        return InputPrivacyKeyStatusTimestamp::read(reader);
    else if (id == 0xbdfb0426)
        return InputPrivacyKeyChatInvite::read(reader);
    else if (id == 0xfabadc5f)
        return InputPrivacyKeyPhoneCall::read(reader);
    else if (id == 0xa4dd4c08)
        return InputPrivacyKeyForwards::read(reader);
    else if (id == 0x5719bacc)
        return InputPrivacyKeyProfilePhoto::read(reader);
    else if (id == 0x352dafa)
        return InputPrivacyKeyPhoneNumber::read(reader);
    else if (id == 0xd1219bdd)
        return InputPrivacyKeyAddedByPhone::read(reader);
    else if (id == 0xbc2eab30)
        return PrivacyKeyStatusTimestamp::read(reader);
    else if (id == 0x500e6dfa)
        return PrivacyKeyChatInvite::read(reader);
    else if (id == 0x3d662b7b)
        return PrivacyKeyPhoneCall::read(reader);
    else if (id == 0x69ec56a3)
        return PrivacyKeyForwards::read(reader);
    else if (id == 0x96151fed)
        return PrivacyKeyProfilePhoto::read(reader);
    else if (id == 0xd19ae46d)
        return PrivacyKeyPhoneNumber::read(reader);
    else if (id == 0x42ffd42b)
        return PrivacyKeyAddedByPhone::read(reader);
    else if (id == 0xd09e07b)
        return InputPrivacyValueAllowContacts::read(reader);
    else if (id == 0x184b35ce)
        return InputPrivacyValueAllowAll::read(reader);
    else if (id == 0x131cc67f)
        return InputPrivacyValueAllowUsers::read(reader);
    else if (id == 0xba52007)
        return InputPrivacyValueDisallowContacts::read(reader);
    else if (id == 0xd66b66c9)
        return InputPrivacyValueDisallowAll::read(reader);
    else if (id == 0x90110467)
        return InputPrivacyValueDisallowUsers::read(reader);
    else if (id == 0x4c81c1ba)
        return InputPrivacyValueAllowChatParticipants::read(reader);
    else if (id == 0xd82363af)
        return InputPrivacyValueDisallowChatParticipants::read(reader);
    else if (id == 0xfffe1bac)
        return PrivacyValueAllowContacts::read(reader);
    else if (id == 0x65427b82)
        return PrivacyValueAllowAll::read(reader);
    else if (id == 0x4d5bbe0c)
        return PrivacyValueAllowUsers::read(reader);
    else if (id == 0xf888fa1a)
        return PrivacyValueDisallowContacts::read(reader);
    else if (id == 0x8b73e763)
        return PrivacyValueDisallowAll::read(reader);
    else if (id == 0xc7f49b7)
        return PrivacyValueDisallowUsers::read(reader);
    else if (id == 0x18be796b)
        return PrivacyValueAllowChatParticipants::read(reader);
    else if (id == 0xacae0690)
        return PrivacyValueDisallowChatParticipants::read(reader);
    else if (id == 0x50a04e45)
        return PrivacyRules::read(reader);
    else if (id == 0xb8d0afdf)
        return AccountDaysTTL::read(reader);
    else if (id == 0x6c37c15c)
        return DocumentAttributeImageSize::read(reader);
    else if (id == 0x11b58939)
        return DocumentAttributeAnimated::read(reader);
    else if (id == 0x6319d612)
        return DocumentAttributeSticker::read(reader);
    else if (id == 0xef02ce6)
        return DocumentAttributeVideo::read(reader);
    else if (id == 0x9852f9c6)
        return DocumentAttributeAudio::read(reader);
    else if (id == 0x15590068)
        return DocumentAttributeFilename::read(reader);
    else if (id == 0x9801d2f7)
        return DocumentAttributeHasStickers::read(reader);
    else if (id == 0xf1749a22)
        return StickersNotModified::read(reader);
    else if (id == 0xe4599bbd)
        return Stickers::read(reader);
    else if (id == 0x12b299d4)
        return StickerPack::read(reader);
    else if (id == 0xe86602c3)
        return AllStickersNotModified::read(reader);
    else if (id == 0xedfd405f)
        return AllStickers::read(reader);
    else if (id == 0x84d19185)
        return AffectedMessages::read(reader);
    else if (id == 0xeb1477e8)
        return WebPageEmpty::read(reader);
    else if (id == 0xc586da1c)
        return WebPagePending::read(reader);
    else if (id == 0xe89c45b2)
        return WebPage::read(reader);
    else if (id == 0x7311ca11)
        return WebPageNotModified::read(reader);
    else if (id == 0xad01d61d)
        return Authorization::read(reader);
    else if (id == 0x1250abde)
        return Authorizations::read(reader);
    else if (id == 0xad2641f8)
        return Password::read(reader);
    else if (id == 0x9a5c33e5)
        return PasswordSettings::read(reader);
    else if (id == 0xc23727c9)
        return PasswordInputSettings::read(reader);
    else if (id == 0x137948a5)
        return PasswordRecovery::read(reader);
    else if (id == 0xa384b779)
        return ReceivedNotifyMessage::read(reader);
    else if (id == 0x6e24fc9d)
        return ChatInviteExported::read(reader);
    else if (id == 0x5a686d7c)
        return ChatInviteAlready::read(reader);
    else if (id == 0xdfc2f58e)
        return ChatInvite::read(reader);
    else if (id == 0x61695cb0)
        return ChatInvitePeek::read(reader);
    else if (id == 0xffb62b95)
        return InputStickerSetEmpty::read(reader);
    else if (id == 0x9de7a269)
        return InputStickerSetID::read(reader);
    else if (id == 0x861cc8a0)
        return InputStickerSetShortName::read(reader);
    else if (id == 0x28703c8)
        return InputStickerSetAnimatedEmoji::read(reader);
    else if (id == 0xe67f520e)
        return InputStickerSetDice::read(reader);
    else if (id == 0xd7df217a)
        return StickerSet::read(reader);
    else if (id == 0xb60a24a6)
        return StickerSet::read(reader);
    else if (id == 0xc27ac8c7)
        return BotCommand::read(reader);
    else if (id == 0x98e81d3a)
        return BotInfo::read(reader);
    else if (id == 0xa2fa4880)
        return KeyboardButton::read(reader);
    else if (id == 0x258aff05)
        return KeyboardButtonUrl::read(reader);
    else if (id == 0x35bbdb6b)
        return KeyboardButtonCallback::read(reader);
    else if (id == 0xb16a6c29)
        return KeyboardButtonRequestPhone::read(reader);
    else if (id == 0xfc796b3f)
        return KeyboardButtonRequestGeoLocation::read(reader);
    else if (id == 0x568a748)
        return KeyboardButtonSwitchInline::read(reader);
    else if (id == 0x50f41ccf)
        return KeyboardButtonGame::read(reader);
    else if (id == 0xafd93fbb)
        return KeyboardButtonBuy::read(reader);
    else if (id == 0x10b78d29)
        return KeyboardButtonUrlAuth::read(reader);
    else if (id == 0xd02e7fd4)
        return InputKeyboardButtonUrlAuth::read(reader);
    else if (id == 0xbbc7515d)
        return KeyboardButtonRequestPoll::read(reader);
    else if (id == 0x77608b83)
        return KeyboardButtonRow::read(reader);
    else if (id == 0xa03e5b85)
        return ReplyKeyboardHide::read(reader);
    else if (id == 0x86b40b08)
        return ReplyKeyboardForceReply::read(reader);
    else if (id == 0x85dd99d1)
        return ReplyKeyboardMarkup::read(reader);
    else if (id == 0x48a30254)
        return ReplyInlineMarkup::read(reader);
    else if (id == 0xbb92ba95)
        return MessageEntityUnknown::read(reader);
    else if (id == 0xfa04579d)
        return MessageEntityMention::read(reader);
    else if (id == 0x6f635b0d)
        return MessageEntityHashtag::read(reader);
    else if (id == 0x6cef8ac7)
        return MessageEntityBotCommand::read(reader);
    else if (id == 0x6ed02538)
        return MessageEntityUrl::read(reader);
    else if (id == 0x64e475c2)
        return MessageEntityEmail::read(reader);
    else if (id == 0xbd610bc9)
        return MessageEntityBold::read(reader);
    else if (id == 0x826f8b60)
        return MessageEntityItalic::read(reader);
    else if (id == 0x28a20571)
        return MessageEntityCode::read(reader);
    else if (id == 0x73924be0)
        return MessageEntityPre::read(reader);
    else if (id == 0x76a6d327)
        return MessageEntityTextUrl::read(reader);
    else if (id == 0x352dca58)
        return MessageEntityMentionName::read(reader);
    else if (id == 0x208e68c9)
        return InputMessageEntityMentionName::read(reader);
    else if (id == 0x9b69e34b)
        return MessageEntityPhone::read(reader);
    else if (id == 0x4c4e743f)
        return MessageEntityCashtag::read(reader);
    else if (id == 0x9c4e7e8b)
        return MessageEntityUnderline::read(reader);
    else if (id == 0xbf0693d4)
        return MessageEntityStrike::read(reader);
    else if (id == 0x20df5d0)
        return MessageEntityBlockquote::read(reader);
    else if (id == 0x761e6af4)
        return MessageEntityBankCard::read(reader);
    else if (id == 0xee8c1e86)
        return InputChannelEmpty::read(reader);
    else if (id == 0xafeb712e)
        return InputChannel::read(reader);
    else if (id == 0x2a286531)
        return InputChannelFromMessage::read(reader);
    else if (id == 0x7f077ad9)
        return ResolvedPeer::read(reader);
    else if (id == 0xae30253)
        return MessageRange::read(reader);
    else if (id == 0x3e11affb)
        return ChannelDifferenceEmpty::read(reader);
    else if (id == 0xa4bcc6fe)
        return ChannelDifferenceTooLong::read(reader);
    else if (id == 0x2064674e)
        return ChannelDifference::read(reader);
    else if (id == 0x94d42ee7)
        return ChannelMessagesFilterEmpty::read(reader);
    else if (id == 0xcd77d957)
        return ChannelMessagesFilter::read(reader);
    else if (id == 0x15ebac1d)
        return ChannelParticipant::read(reader);
    else if (id == 0xa3289a6d)
        return ChannelParticipantSelf::read(reader);
    else if (id == 0x447dca4b)
        return ChannelParticipantCreator::read(reader);
    else if (id == 0xccbebbaf)
        return ChannelParticipantAdmin::read(reader);
    else if (id == 0x50a1dfd6)
        return ChannelParticipantBanned::read(reader);
    else if (id == 0x1b03f006)
        return ChannelParticipantLeft::read(reader);
    else if (id == 0xde3f3c79)
        return ChannelParticipantsRecent::read(reader);
    else if (id == 0xb4608969)
        return ChannelParticipantsAdmins::read(reader);
    else if (id == 0xa3b54985)
        return ChannelParticipantsKicked::read(reader);
    else if (id == 0xb0d1865b)
        return ChannelParticipantsBots::read(reader);
    else if (id == 0x1427a5e1)
        return ChannelParticipantsBanned::read(reader);
    else if (id == 0x656ac4b)
        return ChannelParticipantsSearch::read(reader);
    else if (id == 0xbb6ae88d)
        return ChannelParticipantsContacts::read(reader);
    else if (id == 0xe04b5ceb)
        return ChannelParticipantsMentions::read(reader);
    else if (id == 0x9ab0feaf)
        return ChannelParticipants::read(reader);
    else if (id == 0xf0173fe9)
        return ChannelParticipantsNotModified::read(reader);
    else if (id == 0xdfb80317)
        return ChannelParticipant::read(reader);
    else if (id == 0x780a0310)
        return TermsOfService::read(reader);
    else if (id == 0xe8025ca2)
        return SavedGifsNotModified::read(reader);
    else if (id == 0x2e0709a5)
        return SavedGifs::read(reader);
    else if (id == 0x3380c786)
        return InputBotInlineMessageMediaAuto::read(reader);
    else if (id == 0x3dcd7a87)
        return InputBotInlineMessageText::read(reader);
    else if (id == 0x96929a85)
        return InputBotInlineMessageMediaGeo::read(reader);
    else if (id == 0x417bbf11)
        return InputBotInlineMessageMediaVenue::read(reader);
    else if (id == 0xa6edbffd)
        return InputBotInlineMessageMediaContact::read(reader);
    else if (id == 0x4b425864)
        return InputBotInlineMessageGame::read(reader);
    else if (id == 0xd7e78225)
        return InputBotInlineMessageMediaInvoice::read(reader);
    else if (id == 0x88bf9319)
        return InputBotInlineResult::read(reader);
    else if (id == 0xa8d864a7)
        return InputBotInlineResultPhoto::read(reader);
    else if (id == 0xfff8fdc4)
        return InputBotInlineResultDocument::read(reader);
    else if (id == 0x4fa417f2)
        return InputBotInlineResultGame::read(reader);
    else if (id == 0x764cf810)
        return BotInlineMessageMediaAuto::read(reader);
    else if (id == 0x8c7f65e2)
        return BotInlineMessageText::read(reader);
    else if (id == 0x51846fd)
        return BotInlineMessageMediaGeo::read(reader);
    else if (id == 0x8a86659c)
        return BotInlineMessageMediaVenue::read(reader);
    else if (id == 0x18d1cdc2)
        return BotInlineMessageMediaContact::read(reader);
    else if (id == 0x354a9b09)
        return BotInlineMessageMediaInvoice::read(reader);
    else if (id == 0x11965f3a)
        return BotInlineResult::read(reader);
    else if (id == 0x17db940b)
        return BotInlineMediaResult::read(reader);
    else if (id == 0x947ca848)
        return BotResults::read(reader);
    else if (id == 0x5dab1af4)
        return ExportedMessageLink::read(reader);
    else if (id == 0x5f777dce)
        return MessageFwdHeader::read(reader);
    else if (id == 0x72a3158c)
        return CodeTypeSms::read(reader);
    else if (id == 0x741cd3e3)
        return CodeTypeCall::read(reader);
    else if (id == 0x226ccefb)
        return CodeTypeFlashCall::read(reader);
    else if (id == 0x3dbb5986)
        return SentCodeTypeApp::read(reader);
    else if (id == 0xc000bba2)
        return SentCodeTypeSms::read(reader);
    else if (id == 0x5353e5a7)
        return SentCodeTypeCall::read(reader);
    else if (id == 0xab03c6d9)
        return SentCodeTypeFlashCall::read(reader);
    else if (id == 0x36585ea4)
        return BotCallbackAnswer::read(reader);
    else if (id == 0x26b5dde6)
        return MessageEditData::read(reader);
    else if (id == 0x890c3d89)
        return InputBotInlineMessageID::read(reader);
    else if (id == 0x3c20629f)
        return InlineBotSwitchPM::read(reader);
    else if (id == 0x3371c354)
        return PeerDialogs::read(reader);
    else if (id == 0xedcdc05b)
        return TopPeer::read(reader);
    else if (id == 0xab661b5b)
        return TopPeerCategoryBotsPM::read(reader);
    else if (id == 0x148677e2)
        return TopPeerCategoryBotsInline::read(reader);
    else if (id == 0x637b7ed)
        return TopPeerCategoryCorrespondents::read(reader);
    else if (id == 0xbd17a14a)
        return TopPeerCategoryGroups::read(reader);
    else if (id == 0x161d9628)
        return TopPeerCategoryChannels::read(reader);
    else if (id == 0x1e76a78c)
        return TopPeerCategoryPhoneCalls::read(reader);
    else if (id == 0xa8406ca9)
        return TopPeerCategoryForwardUsers::read(reader);
    else if (id == 0xfbeec0f0)
        return TopPeerCategoryForwardChats::read(reader);
    else if (id == 0xfb834291)
        return TopPeerCategoryPeers::read(reader);
    else if (id == 0xde266ef5)
        return TopPeersNotModified::read(reader);
    else if (id == 0x70b772a8)
        return TopPeers::read(reader);
    else if (id == 0xb52c939d)
        return TopPeersDisabled::read(reader);
    else if (id == 0x1b0c841a)
        return DraftMessageEmpty::read(reader);
    else if (id == 0xfd8e711f)
        return DraftMessage::read(reader);
    else if (id == 0xc6dc0c66)
        return FeaturedStickersNotModified::read(reader);
    else if (id == 0xb6abc341)
        return FeaturedStickers::read(reader);
    else if (id == 0xb17f890)
        return RecentStickersNotModified::read(reader);
    else if (id == 0x22f3afb3)
        return RecentStickers::read(reader);
    else if (id == 0x4fcba9c8)
        return ArchivedStickers::read(reader);
    else if (id == 0x38641628)
        return StickerSetInstallResultSuccess::read(reader);
    else if (id == 0x35e410a8)
        return StickerSetInstallResultArchive::read(reader);
    else if (id == 0x6410a5d2)
        return StickerSetCovered::read(reader);
    else if (id == 0x3407e51b)
        return StickerSetMultiCovered::read(reader);
    else if (id == 0xaed6dbb2)
        return MaskCoords::read(reader);
    else if (id == 0x4a992157)
        return InputStickeredMediaPhoto::read(reader);
    else if (id == 0x438865b)
        return InputStickeredMediaDocument::read(reader);
    else if (id == 0xbdf9653b)
        return Game::read(reader);
    else if (id == 0x32c3e77)
        return InputGameID::read(reader);
    else if (id == 0xc331e80a)
        return InputGameShortName::read(reader);
    else if (id == 0x58fffcd0)
        return HighScore::read(reader);
    else if (id == 0x9a3bfd99)
        return HighScores::read(reader);
    else if (id == 0xdc3d824f)
        return TextEmpty::read(reader);
    else if (id == 0x744694e0)
        return TextPlain::read(reader);
    else if (id == 0x6724abc4)
        return TextBold::read(reader);
    else if (id == 0xd912a59c)
        return TextItalic::read(reader);
    else if (id == 0xc12622c4)
        return TextUnderline::read(reader);
    else if (id == 0x9bf8bb95)
        return TextStrike::read(reader);
    else if (id == 0x6c3f19b9)
        return TextFixed::read(reader);
    else if (id == 0x3c2884c1)
        return TextUrl::read(reader);
    else if (id == 0xde5a0dd6)
        return TextEmail::read(reader);
    else if (id == 0x7e6260d7)
        return TextConcat::read(reader);
    else if (id == 0xed6a8504)
        return TextSubscript::read(reader);
    else if (id == 0xc7fb5e01)
        return TextSuperscript::read(reader);
    else if (id == 0x34b8621)
        return TextMarked::read(reader);
    else if (id == 0x1ccb966a)
        return TextPhone::read(reader);
    else if (id == 0x81ccf4f)
        return TextImage::read(reader);
    else if (id == 0x35553762)
        return TextAnchor::read(reader);
    else if (id == 0x13567e8a)
        return PageBlockUnsupported::read(reader);
    else if (id == 0x70abc3fd)
        return PageBlockTitle::read(reader);
    else if (id == 0x8ffa9a1f)
        return PageBlockSubtitle::read(reader);
    else if (id == 0xbaafe5e0)
        return PageBlockAuthorDate::read(reader);
    else if (id == 0xbfd064ec)
        return PageBlockHeader::read(reader);
    else if (id == 0xf12bb6e1)
        return PageBlockSubheader::read(reader);
    else if (id == 0x467a0766)
        return PageBlockParagraph::read(reader);
    else if (id == 0xc070d93e)
        return PageBlockPreformatted::read(reader);
    else if (id == 0x48870999)
        return PageBlockFooter::read(reader);
    else if (id == 0xdb20b188)
        return PageBlockDivider::read(reader);
    else if (id == 0xce0d37b0)
        return PageBlockAnchor::read(reader);
    else if (id == 0xe4e88011)
        return PageBlockList::read(reader);
    else if (id == 0x263d7c26)
        return PageBlockBlockquote::read(reader);
    else if (id == 0x4f4456d3)
        return PageBlockPullquote::read(reader);
    else if (id == 0x1759c560)
        return PageBlockPhoto::read(reader);
    else if (id == 0x7c8fe7b6)
        return PageBlockVideo::read(reader);
    else if (id == 0x39f23300)
        return PageBlockCover::read(reader);
    else if (id == 0xa8718dc5)
        return PageBlockEmbed::read(reader);
    else if (id == 0xf259a80b)
        return PageBlockEmbedPost::read(reader);
    else if (id == 0x65a0fa4d)
        return PageBlockCollage::read(reader);
    else if (id == 0x31f9590)
        return PageBlockSlideshow::read(reader);
    else if (id == 0xef1751b5)
        return PageBlockChannel::read(reader);
    else if (id == 0x804361ea)
        return PageBlockAudio::read(reader);
    else if (id == 0x1e148390)
        return PageBlockKicker::read(reader);
    else if (id == 0xbf4dea82)
        return PageBlockTable::read(reader);
    else if (id == 0x9a8ae1e1)
        return PageBlockOrderedList::read(reader);
    else if (id == 0x76768bed)
        return PageBlockDetails::read(reader);
    else if (id == 0x16115a96)
        return PageBlockRelatedArticles::read(reader);
    else if (id == 0xa44f3ef6)
        return PageBlockMap::read(reader);
    else if (id == 0x85e42301)
        return PhoneCallDiscardReasonMissed::read(reader);
    else if (id == 0xe095c1a0)
        return PhoneCallDiscardReasonDisconnect::read(reader);
    else if (id == 0x57adc690)
        return PhoneCallDiscardReasonHangup::read(reader);
    else if (id == 0xfaf7e8c9)
        return PhoneCallDiscardReasonBusy::read(reader);
    else if (id == 0x7d748d04)
        return DataJSON::read(reader);
    else if (id == 0xcb296bf8)
        return LabeledPrice::read(reader);
    else if (id == 0xcd886e0)
        return Invoice::read(reader);
    else if (id == 0xea02c27e)
        return PaymentCharge::read(reader);
    else if (id == 0x1e8caaeb)
        return PostAddress::read(reader);
    else if (id == 0x909c3f94)
        return PaymentRequestedInfo::read(reader);
    else if (id == 0xcdc27a1f)
        return PaymentSavedCredentialsCard::read(reader);
    else if (id == 0x1c570ed1)
        return WebDocument::read(reader);
    else if (id == 0xf9c8bcc6)
        return WebDocumentNoProxy::read(reader);
    else if (id == 0x9bed434d)
        return InputWebDocument::read(reader);
    else if (id == 0xc239d686)
        return InputWebFileLocation::read(reader);
    else if (id == 0x9f2221c9)
        return InputWebFileGeoPointLocation::read(reader);
    else if (id == 0x21e753bc)
        return WebFile::read(reader);
    else if (id == 0x8d0b2415)
        return PaymentForm::read(reader);
    else if (id == 0xd1451883)
        return ValidatedRequestedInfo::read(reader);
    else if (id == 0x4e5f810d)
        return PaymentResult::read(reader);
    else if (id == 0xd8411139)
        return PaymentVerificationNeeded::read(reader);
    else if (id == 0x10b555d0)
        return PaymentReceipt::read(reader);
    else if (id == 0xfb8fe43c)
        return SavedInfo::read(reader);
    else if (id == 0xc10eb2cf)
        return InputPaymentCredentialsSaved::read(reader);
    else if (id == 0x3417d728)
        return InputPaymentCredentials::read(reader);
    else if (id == 0xaa1c39f)
        return InputPaymentCredentialsApplePay::read(reader);
    else if (id == 0x8ac32801)
        return InputPaymentCredentialsGooglePay::read(reader);
    else if (id == 0xdb64fd34)
        return TmpPassword::read(reader);
    else if (id == 0xb6213cdf)
        return ShippingOption::read(reader);
    else if (id == 0xffa0a496)
        return InputStickerSetItem::read(reader);
    else if (id == 0x1e36fded)
        return InputPhoneCall::read(reader);
    else if (id == 0x5366c915)
        return PhoneCallEmpty::read(reader);
    else if (id == 0x1b8f4ad1)
        return PhoneCallWaiting::read(reader);
    else if (id == 0x87eabb53)
        return PhoneCallRequested::read(reader);
    else if (id == 0x997c454a)
        return PhoneCallAccepted::read(reader);
    else if (id == 0x8742ae7f)
        return PhoneCall::read(reader);
    else if (id == 0x50ca4de1)
        return PhoneCallDiscarded::read(reader);
    else if (id == 0x9d4c17c0)
        return PhoneConnection::read(reader);
    else if (id == 0x635fe375)
        return PhoneConnectionWebrtc::read(reader);
    else if (id == 0xfc878fc8)
        return PhoneCallProtocol::read(reader);
    else if (id == 0xec82e140)
        return PhoneCall::read(reader);
    else if (id == 0xeea8e46e)
        return CdnFileReuploadNeeded::read(reader);
    else if (id == 0xa99fca4f)
        return CdnFile::read(reader);
    else if (id == 0xc982eaba)
        return CdnPublicKey::read(reader);
    else if (id == 0x5725e40a)
        return CdnConfig::read(reader);
    else if (id == 0xcad181f6)
        return LangPackString::read(reader);
    else if (id == 0x6c47ac9f)
        return LangPackStringPluralized::read(reader);
    else if (id == 0x2979eeb2)
        return LangPackStringDeleted::read(reader);
    else if (id == 0xf385c1f6)
        return LangPackDifference::read(reader);
    else if (id == 0xeeca5ce3)
        return LangPackLanguage::read(reader);
    else if (id == 0xe6dfb825)
        return ChannelAdminLogEventActionChangeTitle::read(reader);
    else if (id == 0x55188a2e)
        return ChannelAdminLogEventActionChangeAbout::read(reader);
    else if (id == 0x6a4afc38)
        return ChannelAdminLogEventActionChangeUsername::read(reader);
    else if (id == 0x434bd2af)
        return ChannelAdminLogEventActionChangePhoto::read(reader);
    else if (id == 0x1b7907ae)
        return ChannelAdminLogEventActionToggleInvites::read(reader);
    else if (id == 0x26ae0971)
        return ChannelAdminLogEventActionToggleSignatures::read(reader);
    else if (id == 0xe9e82c18)
        return ChannelAdminLogEventActionUpdatePinned::read(reader);
    else if (id == 0x709b2405)
        return ChannelAdminLogEventActionEditMessage::read(reader);
    else if (id == 0x42e047bb)
        return ChannelAdminLogEventActionDeleteMessage::read(reader);
    else if (id == 0x183040d3)
        return ChannelAdminLogEventActionParticipantJoin::read(reader);
    else if (id == 0xf89777f2)
        return ChannelAdminLogEventActionParticipantLeave::read(reader);
    else if (id == 0xe31c34d8)
        return ChannelAdminLogEventActionParticipantInvite::read(reader);
    else if (id == 0xe6d83d7e)
        return ChannelAdminLogEventActionParticipantToggleBan::read(reader);
    else if (id == 0xd5676710)
        return ChannelAdminLogEventActionParticipantToggleAdmin::read(reader);
    else if (id == 0xb1c3caa7)
        return ChannelAdminLogEventActionChangeStickerSet::read(reader);
    else if (id == 0x5f5c95f1)
        return ChannelAdminLogEventActionTogglePreHistoryHidden::read(reader);
    else if (id == 0x2df5fc0a)
        return ChannelAdminLogEventActionDefaultBannedRights::read(reader);
    else if (id == 0x8f079643)
        return ChannelAdminLogEventActionStopPoll::read(reader);
    else if (id == 0xa26f881b)
        return ChannelAdminLogEventActionChangeLinkedChat::read(reader);
    else if (id == 0xe6b76ae)
        return ChannelAdminLogEventActionChangeLocation::read(reader);
    else if (id == 0x53909779)
        return ChannelAdminLogEventActionToggleSlowMode::read(reader);
    else if (id == 0x23209745)
        return ChannelAdminLogEventActionStartGroupCall::read(reader);
    else if (id == 0xdb9f9140)
        return ChannelAdminLogEventActionDiscardGroupCall::read(reader);
    else if (id == 0xf92424d2)
        return ChannelAdminLogEventActionParticipantMute::read(reader);
    else if (id == 0xe64429c0)
        return ChannelAdminLogEventActionParticipantUnmute::read(reader);
    else if (id == 0x56d6a247)
        return ChannelAdminLogEventActionToggleGroupCallSetting::read(reader);
    else if (id == 0x5cdada77)
        return ChannelAdminLogEventActionParticipantJoinByInvite::read(reader);
    else if (id == 0x5a50fca4)
        return ChannelAdminLogEventActionExportedInviteDelete::read(reader);
    else if (id == 0x410a134e)
        return ChannelAdminLogEventActionExportedInviteRevoke::read(reader);
    else if (id == 0xe90ebb59)
        return ChannelAdminLogEventActionExportedInviteEdit::read(reader);
    else if (id == 0x3e7f6847)
        return ChannelAdminLogEventActionParticipantVolume::read(reader);
    else if (id == 0x6e941a38)
        return ChannelAdminLogEventActionChangeHistoryTTL::read(reader);
    else if (id == 0x3b5a3e40)
        return ChannelAdminLogEvent::read(reader);
    else if (id == 0xed8af74d)
        return AdminLogResults::read(reader);
    else if (id == 0xea107ae4)
        return ChannelAdminLogEventsFilter::read(reader);
    else if (id == 0x5ce14175)
        return PopularContact::read(reader);
    else if (id == 0x9e8fa6d3)
        return FavedStickersNotModified::read(reader);
    else if (id == 0xf37f2f16)
        return FavedStickers::read(reader);
    else if (id == 0x46e1d13d)
        return RecentMeUrlUnknown::read(reader);
    else if (id == 0x8dbc3336)
        return RecentMeUrlUser::read(reader);
    else if (id == 0xa01b22f9)
        return RecentMeUrlChat::read(reader);
    else if (id == 0xeb49081d)
        return RecentMeUrlChatInvite::read(reader);
    else if (id == 0xbc0a57dc)
        return RecentMeUrlStickerSet::read(reader);
    else if (id == 0xe0310d7)
        return RecentMeUrls::read(reader);
    else if (id == 0x1cc6e91f)
        return InputSingleMedia::read(reader);
    else if (id == 0xcac943f2)
        return WebAuthorization::read(reader);
    else if (id == 0xed56c9fc)
        return WebAuthorizations::read(reader);
    else if (id == 0xa676a322)
        return InputMessageID::read(reader);
    else if (id == 0xbad88395)
        return InputMessageReplyTo::read(reader);
    else if (id == 0x86872538)
        return InputMessagePinned::read(reader);
    else if (id == 0xacfa1a7e)
        return InputMessageCallbackQuery::read(reader);
    else if (id == 0xfcaafeb7)
        return InputDialogPeer::read(reader);
    else if (id == 0x64600527)
        return InputDialogPeerFolder::read(reader);
    else if (id == 0xe56dbf05)
        return DialogPeer::read(reader);
    else if (id == 0x514519e2)
        return DialogPeerFolder::read(reader);
    else if (id == 0xd54b65d)
        return FoundStickerSetsNotModified::read(reader);
    else if (id == 0x5108d648)
        return FoundStickerSets::read(reader);
    else if (id == 0x6242c773)
        return FileHash::read(reader);
    else if (id == 0x75588b3f)
        return InputClientProxy::read(reader);
    else if (id == 0xe3309f7f)
        return TermsOfServiceUpdateEmpty::read(reader);
    else if (id == 0x28ecf961)
        return TermsOfServiceUpdate::read(reader);
    else if (id == 0x3334b0f0)
        return InputSecureFileUploaded::read(reader);
    else if (id == 0x5367e5be)
        return InputSecureFile::read(reader);
    else if (id == 0x64199744)
        return SecureFileEmpty::read(reader);
    else if (id == 0xe0277a62)
        return SecureFile::read(reader);
    else if (id == 0x8aeabec3)
        return SecureData::read(reader);
    else if (id == 0x7d6099dd)
        return SecurePlainPhone::read(reader);
    else if (id == 0x21ec5a5f)
        return SecurePlainEmail::read(reader);
    else if (id == 0x9d2a81e3)
        return SecureValueTypePersonalDetails::read(reader);
    else if (id == 0x3dac6a00)
        return SecureValueTypePassport::read(reader);
    else if (id == 0x6e425c4)
        return SecureValueTypeDriverLicense::read(reader);
    else if (id == 0xa0d0744b)
        return SecureValueTypeIdentityCard::read(reader);
    else if (id == 0x99a48f23)
        return SecureValueTypeInternalPassport::read(reader);
    else if (id == 0xcbe31e26)
        return SecureValueTypeAddress::read(reader);
    else if (id == 0xfc36954e)
        return SecureValueTypeUtilityBill::read(reader);
    else if (id == 0x89137c0d)
        return SecureValueTypeBankStatement::read(reader);
    else if (id == 0x8b883488)
        return SecureValueTypeRentalAgreement::read(reader);
    else if (id == 0x99e3806a)
        return SecureValueTypePassportRegistration::read(reader);
    else if (id == 0xea02ec33)
        return SecureValueTypeTemporaryRegistration::read(reader);
    else if (id == 0xb320aadb)
        return SecureValueTypePhone::read(reader);
    else if (id == 0x8e3ca7ee)
        return SecureValueTypeEmail::read(reader);
    else if (id == 0x187fa0ca)
        return SecureValue::read(reader);
    else if (id == 0xdb21d0a7)
        return InputSecureValue::read(reader);
    else if (id == 0xed1ecdb0)
        return SecureValueHash::read(reader);
    else if (id == 0xe8a40bd9)
        return SecureValueErrorData::read(reader);
    else if (id == 0xbe3dfa)
        return SecureValueErrorFrontSide::read(reader);
    else if (id == 0x868a2aa5)
        return SecureValueErrorReverseSide::read(reader);
    else if (id == 0xe537ced6)
        return SecureValueErrorSelfie::read(reader);
    else if (id == 0x7a700873)
        return SecureValueErrorFile::read(reader);
    else if (id == 0x666220e9)
        return SecureValueErrorFiles::read(reader);
    else if (id == 0x869d758f)
        return SecureValueError::read(reader);
    else if (id == 0xa1144770)
        return SecureValueErrorTranslationFile::read(reader);
    else if (id == 0x34636dd8)
        return SecureValueErrorTranslationFiles::read(reader);
    else if (id == 0x33f0ea47)
        return SecureCredentialsEncrypted::read(reader);
    else if (id == 0xad2e1cd8)
        return AuthorizationForm::read(reader);
    else if (id == 0x811f854f)
        return SentEmailCode::read(reader);
    else if (id == 0x66afa166)
        return DeepLinkInfoEmpty::read(reader);
    else if (id == 0x6a4ee832)
        return DeepLinkInfo::read(reader);
    else if (id == 0x1142bd56)
        return SavedPhoneContact::read(reader);
    else if (id == 0x4dba4501)
        return Takeout::read(reader);
    else if (id == 0xd45ab096)
        return PasswordKdfAlgoUnknown::read(reader);
    else if (id == 0x4a8537)
        return SecurePasswordKdfAlgoUnknown::read(reader);
    else if (id == 0x1527bcac)
        return SecureSecretSettings::read(reader);
    else if (id == 0x9880f658)
        return InputCheckPasswordEmpty::read(reader);
    else if (id == 0xd27ff082)
        return InputCheckPasswordSRP::read(reader);
    else if (id == 0x829d99da)
        return SecureRequiredType::read(reader);
    else if (id == 0x27477b4)
        return SecureRequiredTypeOneOf::read(reader);
    else if (id == 0xbfb9f457)
        return PassportConfigNotModified::read(reader);
    else if (id == 0xa098d6af)
        return PassportConfig::read(reader);
    else if (id == 0x1d1b1245)
        return InputAppEvent::read(reader);
    else if (id == 0xc0de1bd9)
        return JsonObjectValue::read(reader);
    else if (id == 0x3f6d7b68)
        return JsonNull::read(reader);
    else if (id == 0xc7345e6a)
        return JsonBool::read(reader);
    else if (id == 0x2be0dfa4)
        return JsonNumber::read(reader);
    else if (id == 0xb71e767a)
        return JsonString::read(reader);
    else if (id == 0xf7444763)
        return JsonArray::read(reader);
    else if (id == 0x99c1d49d)
        return JsonObject::read(reader);
    else if (id == 0x34566b6a)
        return PageTableCell::read(reader);
    else if (id == 0xe0c0c5e5)
        return PageTableRow::read(reader);
    else if (id == 0x6f747657)
        return PageCaption::read(reader);
    else if (id == 0xb92fb6cd)
        return PageListItemText::read(reader);
    else if (id == 0x25e073fc)
        return PageListItemBlocks::read(reader);
    else if (id == 0x5e068047)
        return PageListOrderedItemText::read(reader);
    else if (id == 0x98dd8936)
        return PageListOrderedItemBlocks::read(reader);
    else if (id == 0xb390dc08)
        return PageRelatedArticle::read(reader);
    else if (id == 0x98657f0d)
        return Page::read(reader);
    else if (id == 0x8c05f1c9)
        return SupportName::read(reader);
    else if (id == 0xf3ae2eed)
        return UserInfoEmpty::read(reader);
    else if (id == 0x1eb3758)
        return UserInfo::read(reader);
    else if (id == 0x6ca9c2e9)
        return PollAnswer::read(reader);
    else if (id == 0x86e18161)
        return Poll::read(reader);
    else if (id == 0x3b6ddad2)
        return PollAnswerVoters::read(reader);
    else if (id == 0xbadcc1a3)
        return PollResults::read(reader);
    else if (id == 0xf041e250)
        return ChatOnlines::read(reader);
    else if (id == 0x47a971e0)
        return StatsURL::read(reader);
    else if (id == 0x5fb224d5)
        return ChatAdminRights::read(reader);
    else if (id == 0x9f120418)
        return ChatBannedRights::read(reader);
    else if (id == 0xe630b979)
        return InputWallPaper::read(reader);
    else if (id == 0x72091c80)
        return InputWallPaperSlug::read(reader);
    else if (id == 0x967a462e)
        return InputWallPaperNoFile::read(reader);
    else if (id == 0x1c199183)
        return WallPapersNotModified::read(reader);
    else if (id == 0x702b65a9)
        return WallPapers::read(reader);
    else if (id == 0xdebebe83)
        return CodeSettings::read(reader);
    else if (id == 0x1dc1bca4)
        return WallPaperSettings::read(reader);
    else if (id == 0xe04232f3)
        return AutoDownloadSettings::read(reader);
    else if (id == 0x63cacf26)
        return AutoDownloadSettings::read(reader);
    else if (id == 0xd5b3b9f9)
        return EmojiKeyword::read(reader);
    else if (id == 0x236df622)
        return EmojiKeywordDeleted::read(reader);
    else if (id == 0x5cc761bd)
        return EmojiKeywordsDifference::read(reader);
    else if (id == 0xa575739d)
        return EmojiURL::read(reader);
    else if (id == 0xb3fb5361)
        return EmojiLanguage::read(reader);
    else if (id == 0xff544e65)
        return Folder::read(reader);
    else if (id == 0xfbd2c296)
        return InputFolderPeer::read(reader);
    else if (id == 0xe9baa668)
        return FolderPeer::read(reader);
    else if (id == 0xe844ebff)
        return SearchCounter::read(reader);
    else if (id == 0x92d33a0e)
        return UrlAuthResultRequest::read(reader);
    else if (id == 0x8f8c0e4e)
        return UrlAuthResultAccepted::read(reader);
    else if (id == 0xa9d6db1f)
        return UrlAuthResultDefault::read(reader);
    else if (id == 0xbfb5ad8b)
        return ChannelLocationEmpty::read(reader);
    else if (id == 0x209b82db)
        return ChannelLocation::read(reader);
    else if (id == 0xca461b5d)
        return PeerLocated::read(reader);
    else if (id == 0xf8ec284b)
        return PeerSelfLocated::read(reader);
    else if (id == 0xd072acb4)
        return RestrictionReason::read(reader);
    else if (id == 0x3c5693e9)
        return InputTheme::read(reader);
    else if (id == 0xf5890df1)
        return InputThemeSlug::read(reader);
    else if (id == 0x28f1114)
        return Theme::read(reader);
    else if (id == 0xf41eb622)
        return ThemesNotModified::read(reader);
    else if (id == 0x7f676421)
        return Themes::read(reader);
    else if (id == 0x629f1980)
        return LoginToken::read(reader);
    else if (id == 0x68e9916)
        return LoginTokenMigrateTo::read(reader);
    else if (id == 0x390d5c5e)
        return LoginTokenSuccess::read(reader);
    else if (id == 0x57e28221)
        return ContentSettings::read(reader);
    else if (id == 0xa927fec5)
        return InactiveChats::read(reader);
    else if (id == 0xc3a12462)
        return BaseThemeClassic::read(reader);
    else if (id == 0xfbd81688)
        return BaseThemeDay::read(reader);
    else if (id == 0xb7b31ea8)
        return BaseThemeNight::read(reader);
    else if (id == 0x6d5f77ee)
        return BaseThemeTinted::read(reader);
    else if (id == 0x5b11125a)
        return BaseThemeArctic::read(reader);
    else if (id == 0xbd507cd1)
        return InputThemeSettings::read(reader);
    else if (id == 0x9c14984a)
        return ThemeSettings::read(reader);
    else if (id == 0x54b56617)
        return WebPageAttributeTheme::read(reader);
    else if (id == 0xa28e5559)
        return MessageUserVote::read(reader);
    else if (id == 0x36377430)
        return MessageUserVoteInputOption::read(reader);
    else if (id == 0xe8fe0de)
        return MessageUserVoteMultiple::read(reader);
    else if (id == 0x823f649)
        return VotesList::read(reader);
    else if (id == 0xf568028a)
        return BankCardOpenUrl::read(reader);
    else if (id == 0x3e24e573)
        return BankCardData::read(reader);
    else if (id == 0x7438f7e8)
        return DialogFilter::read(reader);
    else if (id == 0x77744d4a)
        return DialogFilterSuggested::read(reader);
    else if (id == 0xb637edaf)
        return StatsDateRangeDays::read(reader);
    else if (id == 0xcb43acde)
        return StatsAbsValueAndPrev::read(reader);
    else if (id == 0xcbce2fe0)
        return StatsPercentValue::read(reader);
    else if (id == 0x4a27eb2d)
        return StatsGraphAsync::read(reader);
    else if (id == 0xbedc9822)
        return StatsGraphError::read(reader);
    else if (id == 0x8ea464b6)
        return StatsGraph::read(reader);
    else if (id == 0xad4fc9bd)
        return MessageInteractionCounters::read(reader);
    else if (id == 0xbdf78394)
        return BroadcastStats::read(reader);
    else if (id == 0x98f6ac75)
        return PromoDataEmpty::read(reader);
    else if (id == 0x8c39793f)
        return PromoData::read(reader);
    else if (id == 0xde33b094)
        return VideoSize::read(reader);
    else if (id == 0x18f3d0f7)
        return StatsGroupTopPoster::read(reader);
    else if (id == 0x6014f412)
        return StatsGroupTopAdmin::read(reader);
    else if (id == 0x31962a4c)
        return StatsGroupTopInviter::read(reader);
    else if (id == 0xef7ff916)
        return MegagroupStats::read(reader);
    else if (id == 0xbea2f424)
        return GlobalPrivacySettings::read(reader);
    else if (id == 0x4203c5ef)
        return CountryCode::read(reader);
    else if (id == 0xc3878e23)
        return Country::read(reader);
    else if (id == 0x93cc1f32)
        return CountriesListNotModified::read(reader);
    else if (id == 0x87d0759e)
        return CountriesList::read(reader);
    else if (id == 0x455b853d)
        return MessageViews::read(reader);
    else if (id == 0xb6c4f543)
        return MessageViews::read(reader);
    else if (id == 0xf5dd8f9d)
        return DiscussionMessage::read(reader);
    else if (id == 0xa6d57763)
        return MessageReplyHeader::read(reader);
    else if (id == 0x4128faac)
        return MessageReplies::read(reader);
    else if (id == 0xe8fd8014)
        return PeerBlocked::read(reader);
    else if (id == 0x8999f295)
        return MessageStats::read(reader);
    else if (id == 0x7780bcb4)
        return GroupCallDiscarded::read(reader);
    else if (id == 0x653dbaad)
        return GroupCall::read(reader);
    else if (id == 0xd8aa840f)
        return InputGroupCall::read(reader);
    else if (id == 0xeba636fe)
        return GroupCallParticipant::read(reader);
    else if (id == 0x9e727aad)
        return GroupCall::read(reader);
    else if (id == 0xf47751b6)
        return GroupParticipants::read(reader);
    else if (id == 0x3081ed9d)
        return InlineQueryPeerTypeSameBotPM::read(reader);
    else if (id == 0x833c0fac)
        return InlineQueryPeerTypePM::read(reader);
    else if (id == 0xd766c50a)
        return InlineQueryPeerTypeChat::read(reader);
    else if (id == 0x5ec4be43)
        return InlineQueryPeerTypeMegagroup::read(reader);
    else if (id == 0x6334ee9a)
        return InlineQueryPeerTypeBroadcast::read(reader);
    else if (id == 0x1662af0b)
        return HistoryImport::read(reader);
    else if (id == 0x5e0fb7b9)
        return HistoryImportParsed::read(reader);
    else if (id == 0xef8d3e6c)
        return AffectedFoundMessages::read(reader);
    else if (id == 0x1e3e6680)
        return ChatInviteImporter::read(reader);
    else if (id == 0xbdc62dcc)
        return ExportedChatInvites::read(reader);
    else if (id == 0x1871be50)
        return ExportedChatInvite::read(reader);
    else if (id == 0x222600ef)
        return ExportedChatInviteReplaced::read(reader);
    else if (id == 0x81b6b00a)
        return ChatInviteImporters::read(reader);
    else if (id == 0xdfd2330f)
        return ChatAdminWithInvites::read(reader);
    else if (id == 0xb69b72d7)
        return ChatAdminsWithInvites::read(reader);
    else if (id == 0xa24de717)
        return CheckedHistoryImportPeer::read(reader);
    else if (id == 0xafe5623f)
        return JoinAsPeers::read(reader);
    else if (id == 0x204bd158)
        return ExportedGroupCallInvite::read(reader);
    else if (id == 0xdcb118b7)
        return GroupCallParticipantVideoSourceGroup::read(reader);
    else if (id == 0x78e41663)
        return GroupCallParticipantVideo::read(reader);
    else if (id == 0x85fea03f)
        return SuggestedShortName::read(reader);
    else if (id == 0x2f6cb2ab)
        return BotCommandScopeDefault::read(reader);
    else if (id == 0x3c4f04d8)
        return BotCommandScopeUsers::read(reader);
    else if (id == 0x6fe1a881)
        return BotCommandScopeChats::read(reader);
    else if (id == 0xb9aa606a)
        return BotCommandScopeChatAdmins::read(reader);
    else if (id == 0xdb9d897d)
        return BotCommandScopePeer::read(reader);
    else if (id == 0x3fd863d1)
        return BotCommandScopePeerAdmins::read(reader);
    else if (id == 0xa1321f3)
        return BotCommandScopePeerUser::read(reader);
    else if (id == 0xcb9f372d)
        return InvokeAfterMsg<TLObject>::read(reader);
    else if (id == 0x3dc4b4f0)
        return InvokeAfterMsgs<TLObject>::read(reader);
    else if (id == 0xc1cd5ea9)
        return InitConnection<TLObject>::read(reader);
    else if (id == 0xda9b0d0d)
        return InvokeWithLayer<TLObject>::read(reader);
    else if (id == 0xbf9459b7)
        return InvokeWithoutUpdates<TLObject>::read(reader);
    else if (id == 0x365275f2)
        return InvokeWithMessagesRange<TLObject>::read(reader);
    else if (id == 0xaca9fd2e)
        return InvokeWithTakeout<TLObject>::read(reader);
    else if (id == 0xa677244f)
        return SendCode::read(reader);
    else if (id == 0x80eee427)
        return SignUp::read(reader);
    else if (id == 0xbcd51581)
        return SignIn::read(reader);
    else if (id == 0x5717da40)
        return LogOut::read(reader);
    else if (id == 0x9fab0d1a)
        return ResetAuthorizations::read(reader);
    else if (id == 0xe5bfffcd)
        return ExportAuthorization::read(reader);
    else if (id == 0xe3ef9613)
        return ImportAuthorization::read(reader);
    else if (id == 0xcdd42a05)
        return BindTempAuthKey::read(reader);
    else if (id == 0x67a3ff2c)
        return ImportBotAuthorization::read(reader);
    else if (id == 0xd18b4d16)
        return CheckPassword::read(reader);
    else if (id == 0xd897bc66)
        return RequestPasswordRecovery::read(reader);
    else if (id == 0x4ea56e92)
        return RecoverPassword::read(reader);
    else if (id == 0x3ef1a9bf)
        return ResendCode::read(reader);
    else if (id == 0x1f040578)
        return CancelCode::read(reader);
    else if (id == 0x8e48a188)
        return DropTempAuthKeys::read(reader);
    else if (id == 0xb1b41517)
        return ExportLoginToken::read(reader);
    else if (id == 0x95ac5ce4)
        return ImportLoginToken::read(reader);
    else if (id == 0xe894ad4d)
        return AcceptLoginToken::read(reader);
    else if (id == 0x68976c6f)
        return RegisterDevice::read(reader);
    else if (id == 0x3076c4bf)
        return UnregisterDevice::read(reader);
    else if (id == 0x84be5b93)
        return UpdateNotifySettings::read(reader);
    else if (id == 0x12b3ad31)
        return GetNotifySettings::read(reader);
    else if (id == 0xdb7e1747)
        return ResetNotifySettings::read(reader);
    else if (id == 0x78515775)
        return UpdateProfile::read(reader);
    else if (id == 0x6628562c)
        return UpdateStatus::read(reader);
    else if (id == 0xaabb1763)
        return GetWallPapers::read(reader);
    else if (id == 0xc5ba3d86)
        return ReportPeer::read(reader);
    else if (id == 0x2714d86c)
        return CheckUsername::read(reader);
    else if (id == 0x3e0bdd7c)
        return UpdateUsername::read(reader);
    else if (id == 0xdadbc950)
        return GetPrivacy::read(reader);
    else if (id == 0xc9f81ce8)
        return SetPrivacy::read(reader);
    else if (id == 0x418d4e0b)
        return DeleteAccount::read(reader);
    else if (id == 0x8fc711d)
        return GetAccountTTL::read(reader);
    else if (id == 0x2442485e)
        return SetAccountTTL::read(reader);
    else if (id == 0x82574ae5)
        return SendChangePhoneCode::read(reader);
    else if (id == 0x70c32edb)
        return ChangePhone::read(reader);
    else if (id == 0x38df3532)
        return UpdateDeviceLocked::read(reader);
    else if (id == 0xe320c158)
        return GetAuthorizations::read(reader);
    else if (id == 0xdf77f3bc)
        return ResetAuthorization::read(reader);
    else if (id == 0x548a30f5)
        return GetPassword::read(reader);
    else if (id == 0x9cd4eaf9)
        return GetPasswordSettings::read(reader);
    else if (id == 0xa59b102f)
        return UpdatePasswordSettings::read(reader);
    else if (id == 0x1b3faa88)
        return SendConfirmPhoneCode::read(reader);
    else if (id == 0x5f2178c3)
        return ConfirmPhone::read(reader);
    else if (id == 0x449e0b51)
        return GetTmpPassword::read(reader);
    else if (id == 0x182e6d6f)
        return GetWebAuthorizations::read(reader);
    else if (id == 0x2d01b9ef)
        return ResetWebAuthorization::read(reader);
    else if (id == 0x682d2594)
        return ResetWebAuthorizations::read(reader);
    else if (id == 0xb288bc7d)
        return GetAllSecureValues::read(reader);
    else if (id == 0x73665bc2)
        return GetSecureValue::read(reader);
    else if (id == 0x899fe31d)
        return SaveSecureValue::read(reader);
    else if (id == 0xb880bc4b)
        return DeleteSecureValue::read(reader);
    else if (id == 0xb86ba8e1)
        return GetAuthorizationForm::read(reader);
    else if (id == 0xe7027c94)
        return AcceptAuthorization::read(reader);
    else if (id == 0xa5a356f9)
        return SendVerifyPhoneCode::read(reader);
    else if (id == 0x4dd3a7f6)
        return VerifyPhone::read(reader);
    else if (id == 0x7011509f)
        return SendVerifyEmailCode::read(reader);
    else if (id == 0xecba39db)
        return VerifyEmail::read(reader);
    else if (id == 0xf05b4804)
        return InitTakeoutSession::read(reader);
    else if (id == 0x1d2652ee)
        return FinishTakeoutSession::read(reader);
    else if (id == 0x8fdf1920)
        return ConfirmPasswordEmail::read(reader);
    else if (id == 0x7a7f2a15)
        return ResendPasswordEmail::read(reader);
    else if (id == 0xc1cbd5b6)
        return CancelPasswordEmail::read(reader);
    else if (id == 0x9f07c728)
        return GetContactSignUpNotification::read(reader);
    else if (id == 0xcff43f61)
        return SetContactSignUpNotification::read(reader);
    else if (id == 0x53577479)
        return GetNotifyExceptions::read(reader);
    else if (id == 0xfc8ddbea)
        return GetWallPaper::read(reader);
    else if (id == 0xdd853661)
        return UploadWallPaper::read(reader);
    else if (id == 0x6c5a5b37)
        return SaveWallPaper::read(reader);
    else if (id == 0xfeed5769)
        return InstallWallPaper::read(reader);
    else if (id == 0xbb3b9804)
        return ResetWallPapers::read(reader);
    else if (id == 0x56da0b3f)
        return GetAutoDownloadSettings::read(reader);
    else if (id == 0x76f36233)
        return SaveAutoDownloadSettings::read(reader);
    else if (id == 0x1c3db333)
        return UploadTheme::read(reader);
    else if (id == 0x8432c21f)
        return CreateTheme::read(reader);
    else if (id == 0x5cb367d5)
        return UpdateTheme::read(reader);
    else if (id == 0xf257106c)
        return SaveTheme::read(reader);
    else if (id == 0x7ae43737)
        return InstallTheme::read(reader);
    else if (id == 0x8d9d742b)
        return GetTheme::read(reader);
    else if (id == 0x285946f8)
        return GetThemes::read(reader);
    else if (id == 0xb574b16b)
        return SetContentSettings::read(reader);
    else if (id == 0x8b9b4dae)
        return GetContentSettings::read(reader);
    else if (id == 0x65ad71dc)
        return GetMultiWallPapers::read(reader);
    else if (id == 0xeb2b4cf6)
        return GetGlobalPrivacySettings::read(reader);
    else if (id == 0x1edaaac2)
        return SetGlobalPrivacySettings::read(reader);
    else if (id == 0xfa8cc6f5)
        return ReportProfilePhoto::read(reader);
    else if (id == 0xd91a548)
        return GetUsers::read(reader);
    else if (id == 0xca30a5b1)
        return GetFullUser::read(reader);
    else if (id == 0x90c894b5)
        return SetSecureValueErrors::read(reader);
    else if (id == 0x2caa4a42)
        return GetContactIDs::read(reader);
    else if (id == 0xc4a353ee)
        return GetStatuses::read(reader);
    else if (id == 0xc023849f)
        return GetContacts::read(reader);
    else if (id == 0x2c800be5)
        return ImportContacts::read(reader);
    else if (id == 0x96a0e00)
        return DeleteContacts::read(reader);
    else if (id == 0x1013fd9e)
        return DeleteByPhones::read(reader);
    else if (id == 0x68cc1411)
        return Block::read(reader);
    else if (id == 0xbea65d50)
        return Unblock::read(reader);
    else if (id == 0xf57c350f)
        return GetBlocked::read(reader);
    else if (id == 0x11f812d8)
        return Search::read(reader);
    else if (id == 0xf93ccba3)
        return ResolveUsername::read(reader);
    else if (id == 0xd4982db5)
        return GetTopPeers::read(reader);
    else if (id == 0x1ae373ac)
        return ResetTopPeerRating::read(reader);
    else if (id == 0x879537f1)
        return ResetSaved::read(reader);
    else if (id == 0x82f1e39f)
        return GetSaved::read(reader);
    else if (id == 0x8514bdda)
        return ToggleTopPeers::read(reader);
    else if (id == 0xe8f463d0)
        return AddContact::read(reader);
    else if (id == 0xf831a20f)
        return AcceptContact::read(reader);
    else if (id == 0xd348bc44)
        return GetLocated::read(reader);
    else if (id == 0x29a8962c)
        return BlockFromReplies::read(reader);
    else if (id == 0x63c66506)
        return GetMessages::read(reader);
    else if (id == 0xa0ee3b73)
        return GetDialogs::read(reader);
    else if (id == 0xdcbb8260)
        return GetHistory::read(reader);
    else if (id == 0xc352eec)
        return Search::read(reader);
    else if (id == 0xe306d3a)
        return ReadHistory::read(reader);
    else if (id == 0x1c015b09)
        return DeleteHistory::read(reader);
    else if (id == 0xe58e95d2)
        return DeleteMessages::read(reader);
    else if (id == 0x5a954c0)
        return ReceivedMessages::read(reader);
    else if (id == 0x58943ee2)
        return SetTyping::read(reader);
    else if (id == 0x520c3870)
        return SendMessage::read(reader);
    else if (id == 0x3491eba9)
        return SendMedia::read(reader);
    else if (id == 0xd9fee60e)
        return ForwardMessages::read(reader);
    else if (id == 0xcf1592db)
        return ReportSpam::read(reader);
    else if (id == 0x3672e09c)
        return GetPeerSettings::read(reader);
    else if (id == 0x8953ab4e)
        return Report::read(reader);
    else if (id == 0x3c6aa187)
        return GetChats::read(reader);
    else if (id == 0x3b831c66)
        return GetFullChat::read(reader);
    else if (id == 0xdc452855)
        return EditChatTitle::read(reader);
    else if (id == 0xca4c79d8)
        return EditChatPhoto::read(reader);
    else if (id == 0xf9a0aa09)
        return AddChatUser::read(reader);
    else if (id == 0xc534459a)
        return DeleteChatUser::read(reader);
    else if (id == 0x9cb126e)
        return CreateChat::read(reader);
    else if (id == 0x26cf8950)
        return GetDhConfig::read(reader);
    else if (id == 0xf64daf43)
        return RequestEncryption::read(reader);
    else if (id == 0x3dbc0415)
        return AcceptEncryption::read(reader);
    else if (id == 0xf393aea0)
        return DiscardEncryption::read(reader);
    else if (id == 0x791451ed)
        return SetEncryptedTyping::read(reader);
    else if (id == 0x7f4b690a)
        return ReadEncryptedHistory::read(reader);
    else if (id == 0x44fa7a15)
        return SendEncrypted::read(reader);
    else if (id == 0x5559481d)
        return SendEncryptedFile::read(reader);
    else if (id == 0x32d439a4)
        return SendEncryptedService::read(reader);
    else if (id == 0x55a5bb66)
        return ReceivedQueue::read(reader);
    else if (id == 0x4b0c8c0f)
        return ReportEncryptedSpam::read(reader);
    else if (id == 0x36a73f77)
        return ReadMessageContents::read(reader);
    else if (id == 0x43d4f2c)
        return GetStickers::read(reader);
    else if (id == 0x1c9618b1)
        return GetAllStickers::read(reader);
    else if (id == 0x8b68b0cc)
        return GetWebPagePreview::read(reader);
    else if (id == 0x14b9bcd7)
        return ExportChatInvite::read(reader);
    else if (id == 0x3eadb1bb)
        return CheckChatInvite::read(reader);
    else if (id == 0x6c50051c)
        return ImportChatInvite::read(reader);
    else if (id == 0x2619a90e)
        return GetStickerSet::read(reader);
    else if (id == 0xc78fe460)
        return InstallStickerSet::read(reader);
    else if (id == 0xf96e55de)
        return UninstallStickerSet::read(reader);
    else if (id == 0xe6df7378)
        return StartBot::read(reader);
    else if (id == 0x5784d3e1)
        return GetMessagesViews::read(reader);
    else if (id == 0xa9e69f2e)
        return EditChatAdmin::read(reader);
    else if (id == 0x15a3b8e3)
        return MigrateChat::read(reader);
    else if (id == 0x4bc6589a)
        return SearchGlobal::read(reader);
    else if (id == 0x78337739)
        return ReorderStickerSets::read(reader);
    else if (id == 0x338e2464)
        return GetDocumentByHash::read(reader);
    else if (id == 0x83bf3d52)
        return GetSavedGifs::read(reader);
    else if (id == 0x327a30cb)
        return SaveGif::read(reader);
    else if (id == 0x514e999d)
        return GetInlineBotResults::read(reader);
    else if (id == 0xeb5ea206)
        return SetInlineBotResults::read(reader);
    else if (id == 0x220815b0)
        return SendInlineBotResult::read(reader);
    else if (id == 0xfda68d36)
        return GetMessageEditData::read(reader);
    else if (id == 0x48f71778)
        return EditMessage::read(reader);
    else if (id == 0x83557dba)
        return EditInlineBotMessage::read(reader);
    else if (id == 0x9342ca07)
        return GetBotCallbackAnswer::read(reader);
    else if (id == 0xd58f130a)
        return SetBotCallbackAnswer::read(reader);
    else if (id == 0xe470bcfd)
        return GetPeerDialogs::read(reader);
    else if (id == 0xbc39e14b)
        return SaveDraft::read(reader);
    else if (id == 0x6a3f8d65)
        return GetAllDrafts::read(reader);
    else if (id == 0x2dacca4f)
        return GetFeaturedStickers::read(reader);
    else if (id == 0x5b118126)
        return ReadFeaturedStickers::read(reader);
    else if (id == 0x5ea192c9)
        return GetRecentStickers::read(reader);
    else if (id == 0x392718f8)
        return SaveRecentSticker::read(reader);
    else if (id == 0x8999602d)
        return ClearRecentStickers::read(reader);
    else if (id == 0x57f17692)
        return GetArchivedStickers::read(reader);
    else if (id == 0x65b8c79f)
        return GetMaskStickers::read(reader);
    else if (id == 0xcc5b67cc)
        return GetAttachedStickers::read(reader);
    else if (id == 0x8ef8ecc0)
        return SetGameScore::read(reader);
    else if (id == 0x15ad9f64)
        return SetInlineGameScore::read(reader);
    else if (id == 0xe822649d)
        return GetGameHighScores::read(reader);
    else if (id == 0xf635e1b)
        return GetInlineGameHighScores::read(reader);
    else if (id == 0xd0a48c4)
        return GetCommonChats::read(reader);
    else if (id == 0xeba80ff0)
        return GetAllChats::read(reader);
    else if (id == 0x32ca8f91)
        return GetWebPage::read(reader);
    else if (id == 0xa731e257)
        return ToggleDialogPin::read(reader);
    else if (id == 0x3b1adf37)
        return ReorderPinnedDialogs::read(reader);
    else if (id == 0xd6b94df2)
        return GetPinnedDialogs::read(reader);
    else if (id == 0xe5f672fa)
        return SetBotShippingResults::read(reader);
    else if (id == 0x9c2dd95)
        return SetBotPrecheckoutResults::read(reader);
    else if (id == 0x519bc2b1)
        return UploadMedia::read(reader);
    else if (id == 0xc97df020)
        return SendScreenshotNotification::read(reader);
    else if (id == 0x21ce0b0e)
        return GetFavedStickers::read(reader);
    else if (id == 0xb9ffc55b)
        return FaveSticker::read(reader);
    else if (id == 0x46578472)
        return GetUnreadMentions::read(reader);
    else if (id == 0xf0189d3)
        return ReadMentions::read(reader);
    else if (id == 0xbbc45b09)
        return GetRecentLocations::read(reader);
    else if (id == 0xcc0110cb)
        return SendMultiMedia::read(reader);
    else if (id == 0x5057c497)
        return UploadEncryptedFile::read(reader);
    else if (id == 0xc2b7d08b)
        return SearchStickerSets::read(reader);
    else if (id == 0x1cff7e08)
        return GetSplitRanges::read(reader);
    else if (id == 0xc286d98f)
        return MarkDialogUnread::read(reader);
    else if (id == 0x22e24e22)
        return GetDialogUnreadMarks::read(reader);
    else if (id == 0x7e58ee9c)
        return ClearAllDrafts::read(reader);
    else if (id == 0xd2aaf7ec)
        return UpdatePinnedMessage::read(reader);
    else if (id == 0x10ea6184)
        return SendVote::read(reader);
    else if (id == 0x73bb643b)
        return GetPollResults::read(reader);
    else if (id == 0x6e2be050)
        return GetOnlines::read(reader);
    else if (id == 0x812c2ae6)
        return GetStatsURL::read(reader);
    else if (id == 0xdef60797)
        return EditChatAbout::read(reader);
    else if (id == 0xa5866b41)
        return EditChatDefaultBannedRights::read(reader);
    else if (id == 0x35a0e062)
        return GetEmojiKeywords::read(reader);
    else if (id == 0x1508b6af)
        return GetEmojiKeywordsDifference::read(reader);
    else if (id == 0x4e9963b2)
        return GetEmojiKeywordsLanguages::read(reader);
    else if (id == 0xd5b10c26)
        return GetEmojiURL::read(reader);
    else if (id == 0x732eef00)
        return GetSearchCounters::read(reader);
    else if (id == 0x198fb446)
        return RequestUrlAuth::read(reader);
    else if (id == 0xb12c7125)
        return AcceptUrlAuth::read(reader);
    else if (id == 0x4facb138)
        return HidePeerSettingsBar::read(reader);
    else if (id == 0xe2c2685b)
        return GetScheduledHistory::read(reader);
    else if (id == 0xbdbb0464)
        return GetScheduledMessages::read(reader);
    else if (id == 0xbd38850a)
        return SendScheduledMessages::read(reader);
    else if (id == 0x59ae2b16)
        return DeleteScheduledMessages::read(reader);
    else if (id == 0xb86e380e)
        return GetPollVotes::read(reader);
    else if (id == 0xb5052fea)
        return ToggleStickerSets::read(reader);
    else if (id == 0xf19ed96d)
        return GetDialogFilters::read(reader);
    else if (id == 0xa29cd42c)
        return GetSuggestedDialogFilters::read(reader);
    else if (id == 0x1ad4a04a)
        return UpdateDialogFilter::read(reader);
    else if (id == 0xc563c1e4)
        return UpdateDialogFiltersOrder::read(reader);
    else if (id == 0x5fe7025b)
        return GetOldFeaturedStickers::read(reader);
    else if (id == 0x24b581ba)
        return GetReplies::read(reader);
    else if (id == 0x446972fd)
        return GetDiscussionMessage::read(reader);
    else if (id == 0xf731a9f4)
        return ReadDiscussion::read(reader);
    else if (id == 0xf025bc8b)
        return UnpinAllMessages::read(reader);
    else if (id == 0x83247d11)
        return DeleteChat::read(reader);
    else if (id == 0xf9cbe409)
        return DeletePhoneCallHistory::read(reader);
    else if (id == 0x43fe19f3)
        return CheckHistoryImport::read(reader);
    else if (id == 0x34090c3b)
        return InitHistoryImport::read(reader);
    else if (id == 0x2a862092)
        return UploadImportedMedia::read(reader);
    else if (id == 0xb43df344)
        return StartHistoryImport::read(reader);
    else if (id == 0xa2b5a3f6)
        return GetExportedChatInvites::read(reader);
    else if (id == 0x73746f5c)
        return GetExportedChatInvite::read(reader);
    else if (id == 0x2e4ffbe)
        return EditExportedChatInvite::read(reader);
    else if (id == 0x56987bd5)
        return DeleteRevokedExportedChatInvites::read(reader);
    else if (id == 0xd464a42b)
        return DeleteExportedChatInvite::read(reader);
    else if (id == 0x3920e6ef)
        return GetAdminsWithInvites::read(reader);
    else if (id == 0x26fb7289)
        return GetChatInviteImporters::read(reader);
    else if (id == 0xb80e5fe4)
        return SetHistoryTTL::read(reader);
    else if (id == 0x5dc60f03)
        return CheckHistoryImportPeer::read(reader);
    else if (id == 0xedd4882a)
        return GetState::read(reader);
    else if (id == 0x25939651)
        return GetDifference::read(reader);
    else if (id == 0x3173d78)
        return GetChannelDifference::read(reader);
    else if (id == 0x72d4742c)
        return UpdateProfilePhoto::read(reader);
    else if (id == 0x89f30f69)
        return UploadProfilePhoto::read(reader);
    else if (id == 0x87cf7f2f)
        return DeletePhotos::read(reader);
    else if (id == 0x91cd32a8)
        return GetUserPhotos::read(reader);
    else if (id == 0xb304a621)
        return SaveFilePart::read(reader);
    else if (id == 0xb15a9afc)
        return GetFile::read(reader);
    else if (id == 0xde7b673d)
        return SaveBigFilePart::read(reader);
    else if (id == 0x24e6818d)
        return GetWebFile::read(reader);
    else if (id == 0x2000bcc3)
        return GetCdnFile::read(reader);
    else if (id == 0x9b2754a8)
        return ReuploadCdnFile::read(reader);
    else if (id == 0x4da54231)
        return GetCdnFileHashes::read(reader);
    else if (id == 0xc7025931)
        return GetFileHashes::read(reader);
    else if (id == 0xc4f9186b)
        return GetConfig::read(reader);
    else if (id == 0x1fb33026)
        return GetNearestDc::read(reader);
    else if (id == 0x522d5a7d)
        return GetAppUpdate::read(reader);
    else if (id == 0x4d392343)
        return GetInviteText::read(reader);
    else if (id == 0x9cdf08cd)
        return GetSupport::read(reader);
    else if (id == 0x9010ef6f)
        return GetAppChangelog::read(reader);
    else if (id == 0xec22cfcd)
        return SetBotUpdatesStatus::read(reader);
    else if (id == 0x52029342)
        return GetCdnConfig::read(reader);
    else if (id == 0x3dc0f114)
        return GetRecentMeUrls::read(reader);
    else if (id == 0x2ca51fd1)
        return GetTermsOfServiceUpdate::read(reader);
    else if (id == 0xee72f79a)
        return AcceptTermsOfService::read(reader);
    else if (id == 0x3fedc75f)
        return GetDeepLinkInfo::read(reader);
    else if (id == 0x98914110)
        return GetAppConfig::read(reader);
    else if (id == 0x6f02f748)
        return SaveAppLog::read(reader);
    else if (id == 0xc661ad08)
        return GetPassportConfig::read(reader);
    else if (id == 0xd360e72c)
        return GetSupportName::read(reader);
    else if (id == 0x38a08d3)
        return GetUserInfo::read(reader);
    else if (id == 0x66b91b70)
        return EditUserInfo::read(reader);
    else if (id == 0xc0977421)
        return GetPromoData::read(reader);
    else if (id == 0x1e251c95)
        return HidePromoData::read(reader);
    else if (id == 0xf50dbaa1)
        return DismissSuggestion::read(reader);
    else if (id == 0x735787a8)
        return GetCountriesList::read(reader);
    else if (id == 0xcc104937)
        return ReadHistory::read(reader);
    else if (id == 0x84c1fd4e)
        return DeleteMessages::read(reader);
    else if (id == 0xd10dd71b)
        return DeleteUserHistory::read(reader);
    else if (id == 0xfe087810)
        return ReportSpam::read(reader);
    else if (id == 0xad8c9a23)
        return GetMessages::read(reader);
    else if (id == 0x123e05e9)
        return GetParticipants::read(reader);
    else if (id == 0xa0ab6cc6)
        return GetParticipant::read(reader);
    else if (id == 0xa7f6bbb)
        return GetChannels::read(reader);
    else if (id == 0x8736a09)
        return GetFullChannel::read(reader);
    else if (id == 0x3d5fb10f)
        return CreateChannel::read(reader);
    else if (id == 0xd33c8902)
        return EditAdmin::read(reader);
    else if (id == 0x566decd0)
        return EditTitle::read(reader);
    else if (id == 0xf12e57c9)
        return EditPhoto::read(reader);
    else if (id == 0x10e6bd2c)
        return CheckUsername::read(reader);
    else if (id == 0x3514b3de)
        return UpdateUsername::read(reader);
    else if (id == 0x24b524c5)
        return JoinChannel::read(reader);
    else if (id == 0xf836aa95)
        return LeaveChannel::read(reader);
    else if (id == 0x199f3a6c)
        return InviteToChannel::read(reader);
    else if (id == 0xc0111fe3)
        return DeleteChannel::read(reader);
    else if (id == 0xe63fadeb)
        return ExportMessageLink::read(reader);
    else if (id == 0x1f69b606)
        return ToggleSignatures::read(reader);
    else if (id == 0xf8b036af)
        return GetAdminedPublicChannels::read(reader);
    else if (id == 0x96e6cd81)
        return EditBanned::read(reader);
    else if (id == 0x33ddf480)
        return GetAdminLog::read(reader);
    else if (id == 0xea8ca4f9)
        return SetStickers::read(reader);
    else if (id == 0xeab5dc38)
        return ReadMessageContents::read(reader);
    else if (id == 0xaf369d42)
        return DeleteHistory::read(reader);
    else if (id == 0xeabbb94c)
        return TogglePreHistoryHidden::read(reader);
    else if (id == 0x8341ecc0)
        return GetLeftChannels::read(reader);
    else if (id == 0xf5dad378)
        return GetGroupsForDiscussion::read(reader);
    else if (id == 0x40582bb2)
        return SetDiscussionGroup::read(reader);
    else if (id == 0x8f38cd1f)
        return EditCreator::read(reader);
    else if (id == 0x58e63f6d)
        return EditLocation::read(reader);
    else if (id == 0xedd49ef0)
        return ToggleSlowMode::read(reader);
    else if (id == 0x11e831ee)
        return GetInactiveChannels::read(reader);
    else if (id == 0xb290c69)
        return ConvertToGigagroup::read(reader);
    else if (id == 0xaa2769ed)
        return SendCustomRequest::read(reader);
    else if (id == 0xe6213f4d)
        return AnswerWebhookJSONQuery::read(reader);
    else if (id == 0x517165a)
        return SetBotCommands::read(reader);
    else if (id == 0x3d8de0f9)
        return ResetBotCommands::read(reader);
    else if (id == 0xe34c0dd6)
        return GetBotCommands::read(reader);
    else if (id == 0x8a333c8d)
        return GetPaymentForm::read(reader);
    else if (id == 0x2478d1cc)
        return GetPaymentReceipt::read(reader);
    else if (id == 0xdb103170)
        return ValidateRequestedInfo::read(reader);
    else if (id == 0x30c3bc9d)
        return SendPaymentForm::read(reader);
    else if (id == 0x227d824b)
        return GetSavedInfo::read(reader);
    else if (id == 0xd83d70c1)
        return ClearSavedInfo::read(reader);
    else if (id == 0x2e79d779)
        return GetBankCardData::read(reader);
    else if (id == 0x9021ab67)
        return CreateStickerSet::read(reader);
    else if (id == 0xf7760f51)
        return RemoveStickerFromSet::read(reader);
    else if (id == 0xffb6d4ca)
        return ChangeStickerPosition::read(reader);
    else if (id == 0x8653febe)
        return AddStickerToSet::read(reader);
    else if (id == 0x9a364e30)
        return SetStickerSetThumb::read(reader);
    else if (id == 0x284b3639)
        return CheckShortName::read(reader);
    else if (id == 0x4dafc503)
        return SuggestShortName::read(reader);
    else if (id == 0x55451fa9)
        return GetCallConfig::read(reader);
    else if (id == 0x42ff96ed)
        return RequestCall::read(reader);
    else if (id == 0x3bd2b4a0)
        return AcceptCall::read(reader);
    else if (id == 0x2efe1722)
        return ConfirmCall::read(reader);
    else if (id == 0x17d54f61)
        return ReceivedCall::read(reader);
    else if (id == 0xb2cbc1c0)
        return DiscardCall::read(reader);
    else if (id == 0x59ead627)
        return SetCallRating::read(reader);
    else if (id == 0x277add7e)
        return SaveCallDebug::read(reader);
    else if (id == 0xff7a9383)
        return SendSignalingData::read(reader);
    else if (id == 0x48cdc6d8)
        return CreateGroupCall::read(reader);
    else if (id == 0xb132ff7b)
        return JoinGroupCall::read(reader);
    else if (id == 0x500377f9)
        return LeaveGroupCall::read(reader);
    else if (id == 0x7b393160)
        return InviteToGroupCall::read(reader);
    else if (id == 0x7a777135)
        return DiscardGroupCall::read(reader);
    else if (id == 0x74bbb43d)
        return ToggleGroupCallSettings::read(reader);
    else if (id == 0xc7cb017)
        return GetGroupCall::read(reader);
    else if (id == 0xc558d8ab)
        return GetGroupParticipants::read(reader);
    else if (id == 0xb59cf977)
        return CheckGroupCall::read(reader);
    else if (id == 0xc02a66d7)
        return ToggleGroupCallRecord::read(reader);
    else if (id == 0xa5273abf)
        return EditGroupCallParticipant::read(reader);
    else if (id == 0x1ca6ac0a)
        return EditGroupCallTitle::read(reader);
    else if (id == 0xef7c213a)
        return GetGroupCallJoinAs::read(reader);
    else if (id == 0xe6aa647f)
        return ExportGroupCallInvite::read(reader);
    else if (id == 0x219c34e6)
        return ToggleGroupCallStartSubscription::read(reader);
    else if (id == 0x5680e342)
        return StartScheduledGroupCall::read(reader);
    else if (id == 0x575e1f8c)
        return SaveDefaultGroupCallJoinAs::read(reader);
    else if (id == 0xcbea6bc4)
        return JoinGroupCallPresentation::read(reader);
    else if (id == 0x1c50d144)
        return LeaveGroupCallPresentation::read(reader);
    else if (id == 0xf2f2330a)
        return GetLangPack::read(reader);
    else if (id == 0xefea3803)
        return GetStrings::read(reader);
    else if (id == 0xcd984aa5)
        return GetDifference::read(reader);
    else if (id == 0x42c6978f)
        return GetLanguages::read(reader);
    else if (id == 0x6a596502)
        return GetLanguage::read(reader);
    else if (id == 0x6847d0ab)
        return EditPeerFolders::read(reader);
    else if (id == 0x1c295881)
        return DeleteFolder::read(reader);
    else if (id == 0xab42441a)
        return GetBroadcastStats::read(reader);
    else if (id == 0x621d5fa0)
        return LoadAsyncGraph::read(reader);
    else if (id == 0xdcdf8607)
        return GetMegagroupStats::read(reader);
    else if (id == 0x5630281b)
        return GetMessagePublicForwards::read(reader);
    else if (id == 0xb6e0a3f5)
        return GetMessageStats::read(reader);
}
