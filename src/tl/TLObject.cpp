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

#include "tl/types.h"

TLObject TLObject::read(Reader reader)
{
    int id = Int::read(reader);

    switch (id)
    {
    case ResPQ::getId():
        return ResPQ::read(reader);

    case PQInnerDataDc::getId():
        return PQInnerDataDc::read(reader);

    case PQInnerDataTempDc::getId():
        return PQInnerDataTempDc::read(reader);

    case ServerDHParamsFail::getId():
        return ServerDHParamsFail::read(reader);

    case ServerDHParamsOk::getId():
        return ServerDHParamsOk::read(reader);

    case ServerDHInnerData::getId():
        return ServerDHInnerData::read(reader);

    case ClientDHInnerData::getId():
        return ClientDHInnerData::read(reader);

    case DhGenOk::getId():
        return DhGenOk::read(reader);

    case DhGenRetry::getId():
        return DhGenRetry::read(reader);

    case DhGenFail::getId():
        return DhGenFail::read(reader);

    case RpcError::getId():
        return RpcError::read(reader);

    case RpcAnswerUnknown::getId():
        return RpcAnswerUnknown::read(reader);

    case RpcAnswerDroppedRunning::getId():
        return RpcAnswerDroppedRunning::read(reader);

    case RpcAnswerDropped::getId():
        return RpcAnswerDropped::read(reader);

    case FutureSalt::getId():
        return FutureSalt::read(reader);

    case FutureSalts::getId():
        return FutureSalts::read(reader);

    case Pong::getId():
        return Pong::read(reader);

    case DestroySessionOk::getId():
        return DestroySessionOk::read(reader);

    case DestroySessionNone::getId():
        return DestroySessionNone::read(reader);

    case NewSessionCreated::getId():
        return NewSessionCreated::read(reader);

    case GzipPacked::getId():
        return GzipPacked::read(reader);

    case MsgsAck::getId():
        return MsgsAck::read(reader);

    case BadMsgNotification::getId():
        return BadMsgNotification::read(reader);

    case BadServerSalt::getId():
        return BadServerSalt::read(reader);

    case MsgResendReq::getId():
        return MsgResendReq::read(reader);

    case MsgsStateReq::getId():
        return MsgsStateReq::read(reader);

    case MsgsStateInfo::getId():
        return MsgsStateInfo::read(reader);

    case MsgsAllInfo::getId():
        return MsgsAllInfo::read(reader);

    case MsgDetailedInfo::getId():
        return MsgDetailedInfo::read(reader);

    case MsgNewDetailedInfo::getId():
        return MsgNewDetailedInfo::read(reader);

    case DestroyAuthKeyOk::getId():
        return DestroyAuthKeyOk::read(reader);

    case DestroyAuthKeyNone::getId():
        return DestroyAuthKeyNone::read(reader);

    case DestroyAuthKeyFail::getId():
        return DestroyAuthKeyFail::read(reader);

    case True::getId():
        return True::read(reader);

    case BoolFalse::getId():
        return BoolFalse::read(reader);

    case BoolTrue::getId():
        return BoolTrue::read(reader);

    case Error::getId():
        return Error::read(reader);

    case IpPort::getId():
        return IpPort::read(reader);

    case IpPortSecret::getId():
        return IpPortSecret::read(reader);

    case AccessPointRule::getId():
        return AccessPointRule::read(reader);

    case help::ConfigSimple::getId():
        return help::ConfigSimple::read(reader);

    case InputPeerPhotoFileLocationLegacy::getId():
        return InputPeerPhotoFileLocationLegacy::read(reader);

    case InputStickerSetThumbLegacy::getId():
        return InputStickerSetThumbLegacy::read(reader);

    case InputPeerEmpty::getId():
        return InputPeerEmpty::read(reader);

    case InputPeerSelf::getId():
        return InputPeerSelf::read(reader);

    case InputPeerChat::getId():
        return InputPeerChat::read(reader);

    case InputPeerUser::getId():
        return InputPeerUser::read(reader);

    case InputPeerChannel::getId():
        return InputPeerChannel::read(reader);

    case InputPeerUserFromMessage::getId():
        return InputPeerUserFromMessage::read(reader);

    case InputPeerChannelFromMessage::getId():
        return InputPeerChannelFromMessage::read(reader);

    case InputUserEmpty::getId():
        return InputUserEmpty::read(reader);

    case InputUserSelf::getId():
        return InputUserSelf::read(reader);

    case InputUser::getId():
        return InputUser::read(reader);

    case InputUserFromMessage::getId():
        return InputUserFromMessage::read(reader);

    case InputPhoneContact::getId():
        return InputPhoneContact::read(reader);

    case InputFile::getId():
        return InputFile::read(reader);

    case InputFileBig::getId():
        return InputFileBig::read(reader);

    case InputMediaEmpty::getId():
        return InputMediaEmpty::read(reader);

    case InputMediaUploadedPhoto::getId():
        return InputMediaUploadedPhoto::read(reader);

    case InputMediaPhoto::getId():
        return InputMediaPhoto::read(reader);

    case InputMediaGeoPoint::getId():
        return InputMediaGeoPoint::read(reader);

    case InputMediaContact::getId():
        return InputMediaContact::read(reader);

    case InputMediaUploadedDocument::getId():
        return InputMediaUploadedDocument::read(reader);

    case InputMediaDocument::getId():
        return InputMediaDocument::read(reader);

    case InputMediaVenue::getId():
        return InputMediaVenue::read(reader);

    case InputMediaPhotoExternal::getId():
        return InputMediaPhotoExternal::read(reader);

    case InputMediaDocumentExternal::getId():
        return InputMediaDocumentExternal::read(reader);

    case InputMediaGame::getId():
        return InputMediaGame::read(reader);

    case InputMediaInvoice::getId():
        return InputMediaInvoice::read(reader);

    case InputMediaGeoLive::getId():
        return InputMediaGeoLive::read(reader);

    case InputMediaPoll::getId():
        return InputMediaPoll::read(reader);

    case InputMediaDice::getId():
        return InputMediaDice::read(reader);

    case InputChatPhotoEmpty::getId():
        return InputChatPhotoEmpty::read(reader);

    case InputChatUploadedPhoto::getId():
        return InputChatUploadedPhoto::read(reader);

    case InputChatPhoto::getId():
        return InputChatPhoto::read(reader);

    case InputGeoPointEmpty::getId():
        return InputGeoPointEmpty::read(reader);

    case InputGeoPoint::getId():
        return InputGeoPoint::read(reader);

    case InputPhotoEmpty::getId():
        return InputPhotoEmpty::read(reader);

    case InputPhoto::getId():
        return InputPhoto::read(reader);

    case InputFileLocation::getId():
        return InputFileLocation::read(reader);

    case InputEncryptedFileLocation::getId():
        return InputEncryptedFileLocation::read(reader);

    case InputDocumentFileLocation::getId():
        return InputDocumentFileLocation::read(reader);

    case InputSecureFileLocation::getId():
        return InputSecureFileLocation::read(reader);

    case InputTakeoutFileLocation::getId():
        return InputTakeoutFileLocation::read(reader);

    case InputPhotoFileLocation::getId():
        return InputPhotoFileLocation::read(reader);

    case InputPhotoLegacyFileLocation::getId():
        return InputPhotoLegacyFileLocation::read(reader);

    case InputPeerPhotoFileLocation::getId():
        return InputPeerPhotoFileLocation::read(reader);

    case InputStickerSetThumb::getId():
        return InputStickerSetThumb::read(reader);

    case InputGroupCallStream::getId():
        return InputGroupCallStream::read(reader);

    case PeerUser::getId():
        return PeerUser::read(reader);

    case PeerChat::getId():
        return PeerChat::read(reader);

    case PeerChannel::getId():
        return PeerChannel::read(reader);

    case storage::FileUnknown::getId():
        return storage::FileUnknown::read(reader);

    case storage::FilePartial::getId():
        return storage::FilePartial::read(reader);

    case storage::FileJpeg::getId():
        return storage::FileJpeg::read(reader);

    case storage::FileGif::getId():
        return storage::FileGif::read(reader);

    case storage::FilePng::getId():
        return storage::FilePng::read(reader);

    case storage::FilePdf::getId():
        return storage::FilePdf::read(reader);

    case storage::FileMp3::getId():
        return storage::FileMp3::read(reader);

    case storage::FileMov::getId():
        return storage::FileMov::read(reader);

    case storage::FileMp4::getId():
        return storage::FileMp4::read(reader);

    case storage::FileWebp::getId():
        return storage::FileWebp::read(reader);

    case UserEmpty::getId():
        return UserEmpty::read(reader);

    case User::getId():
        return User::read(reader);

    case UserProfilePhotoEmpty::getId():
        return UserProfilePhotoEmpty::read(reader);

    case UserProfilePhoto::getId():
        return UserProfilePhoto::read(reader);

    case UserStatusEmpty::getId():
        return UserStatusEmpty::read(reader);

    case UserStatusOnline::getId():
        return UserStatusOnline::read(reader);

    case UserStatusOffline::getId():
        return UserStatusOffline::read(reader);

    case UserStatusRecently::getId():
        return UserStatusRecently::read(reader);

    case UserStatusLastWeek::getId():
        return UserStatusLastWeek::read(reader);

    case UserStatusLastMonth::getId():
        return UserStatusLastMonth::read(reader);

    case ChatEmpty::getId():
        return ChatEmpty::read(reader);

    case Chat::getId():
        return Chat::read(reader);

    case ChatForbidden::getId():
        return ChatForbidden::read(reader);

    case Channel::getId():
        return Channel::read(reader);

    case ChannelForbidden::getId():
        return ChannelForbidden::read(reader);

    case ChatFull::getId():
        return ChatFull::read(reader);

    case ChannelFull::getId():
        return ChannelFull::read(reader);

    case ChatParticipant::getId():
        return ChatParticipant::read(reader);

    case ChatParticipantCreator::getId():
        return ChatParticipantCreator::read(reader);

    case ChatParticipantAdmin::getId():
        return ChatParticipantAdmin::read(reader);

    case ChatParticipantsForbidden::getId():
        return ChatParticipantsForbidden::read(reader);

    case ChatParticipants::getId():
        return ChatParticipants::read(reader);

    case ChatPhotoEmpty::getId():
        return ChatPhotoEmpty::read(reader);

    case ChatPhoto::getId():
        return ChatPhoto::read(reader);

    case MessageEmpty::getId():
        return MessageEmpty::read(reader);

    case Message::getId():
        return Message::read(reader);

    case MessageService::getId():
        return MessageService::read(reader);

    case MessageMediaEmpty::getId():
        return MessageMediaEmpty::read(reader);

    case MessageMediaPhoto::getId():
        return MessageMediaPhoto::read(reader);

    case MessageMediaGeo::getId():
        return MessageMediaGeo::read(reader);

    case MessageMediaContact::getId():
        return MessageMediaContact::read(reader);

    case MessageMediaUnsupported::getId():
        return MessageMediaUnsupported::read(reader);

    case MessageMediaDocument::getId():
        return MessageMediaDocument::read(reader);

    case MessageMediaWebPage::getId():
        return MessageMediaWebPage::read(reader);

    case MessageMediaVenue::getId():
        return MessageMediaVenue::read(reader);

    case MessageMediaGame::getId():
        return MessageMediaGame::read(reader);

    case MessageMediaInvoice::getId():
        return MessageMediaInvoice::read(reader);

    case MessageMediaGeoLive::getId():
        return MessageMediaGeoLive::read(reader);

    case MessageMediaPoll::getId():
        return MessageMediaPoll::read(reader);

    case MessageMediaDice::getId():
        return MessageMediaDice::read(reader);

    case MessageActionEmpty::getId():
        return MessageActionEmpty::read(reader);

    case MessageActionChatCreate::getId():
        return MessageActionChatCreate::read(reader);

    case MessageActionChatEditTitle::getId():
        return MessageActionChatEditTitle::read(reader);

    case MessageActionChatEditPhoto::getId():
        return MessageActionChatEditPhoto::read(reader);

    case MessageActionChatDeletePhoto::getId():
        return MessageActionChatDeletePhoto::read(reader);

    case MessageActionChatAddUser::getId():
        return MessageActionChatAddUser::read(reader);

    case MessageActionChatDeleteUser::getId():
        return MessageActionChatDeleteUser::read(reader);

    case MessageActionChatJoinedByLink::getId():
        return MessageActionChatJoinedByLink::read(reader);

    case MessageActionChannelCreate::getId():
        return MessageActionChannelCreate::read(reader);

    case MessageActionChatMigrateTo::getId():
        return MessageActionChatMigrateTo::read(reader);

    case MessageActionChannelMigrateFrom::getId():
        return MessageActionChannelMigrateFrom::read(reader);

    case MessageActionPinMessage::getId():
        return MessageActionPinMessage::read(reader);

    case MessageActionHistoryClear::getId():
        return MessageActionHistoryClear::read(reader);

    case MessageActionGameScore::getId():
        return MessageActionGameScore::read(reader);

    case MessageActionPaymentSentMe::getId():
        return MessageActionPaymentSentMe::read(reader);

    case MessageActionPaymentSent::getId():
        return MessageActionPaymentSent::read(reader);

    case MessageActionPhoneCall::getId():
        return MessageActionPhoneCall::read(reader);

    case MessageActionScreenshotTaken::getId():
        return MessageActionScreenshotTaken::read(reader);

    case MessageActionCustomAction::getId():
        return MessageActionCustomAction::read(reader);

    case MessageActionBotAllowed::getId():
        return MessageActionBotAllowed::read(reader);

    case MessageActionSecureValuesSentMe::getId():
        return MessageActionSecureValuesSentMe::read(reader);

    case MessageActionSecureValuesSent::getId():
        return MessageActionSecureValuesSent::read(reader);

    case MessageActionContactSignUp::getId():
        return MessageActionContactSignUp::read(reader);

    case MessageActionGeoProximityReached::getId():
        return MessageActionGeoProximityReached::read(reader);

    case MessageActionGroupCall::getId():
        return MessageActionGroupCall::read(reader);

    case MessageActionInviteToGroupCall::getId():
        return MessageActionInviteToGroupCall::read(reader);

    case MessageActionSetMessagesTTL::getId():
        return MessageActionSetMessagesTTL::read(reader);

    case MessageActionGroupCallScheduled::getId():
        return MessageActionGroupCallScheduled::read(reader);

    case Dialog::getId():
        return Dialog::read(reader);

    case DialogFolder::getId():
        return DialogFolder::read(reader);

    case PhotoEmpty::getId():
        return PhotoEmpty::read(reader);

    case Photo::getId():
        return Photo::read(reader);

    case PhotoSizeEmpty::getId():
        return PhotoSizeEmpty::read(reader);

    case PhotoSize::getId():
        return PhotoSize::read(reader);

    case PhotoCachedSize::getId():
        return PhotoCachedSize::read(reader);

    case PhotoStrippedSize::getId():
        return PhotoStrippedSize::read(reader);

    case PhotoSizeProgressive::getId():
        return PhotoSizeProgressive::read(reader);

    case PhotoPathSize::getId():
        return PhotoPathSize::read(reader);

    case GeoPointEmpty::getId():
        return GeoPointEmpty::read(reader);

    case GeoPoint::getId():
        return GeoPoint::read(reader);

    case auth::SentCode::getId():
        return auth::SentCode::read(reader);

    case auth::Authorization::getId():
        return auth::Authorization::read(reader);

    case auth::AuthorizationSignUpRequired::getId():
        return auth::AuthorizationSignUpRequired::read(reader);

    case auth::ExportedAuthorization::getId():
        return auth::ExportedAuthorization::read(reader);

    case InputNotifyPeer::getId():
        return InputNotifyPeer::read(reader);

    case InputNotifyUsers::getId():
        return InputNotifyUsers::read(reader);

    case InputNotifyChats::getId():
        return InputNotifyChats::read(reader);

    case InputNotifyBroadcasts::getId():
        return InputNotifyBroadcasts::read(reader);

    case InputPeerNotifySettings::getId():
        return InputPeerNotifySettings::read(reader);

    case PeerNotifySettings::getId():
        return PeerNotifySettings::read(reader);

    case PeerSettings::getId():
        return PeerSettings::read(reader);

    case WallPaper::getId():
        return WallPaper::read(reader);

    case WallPaperNoFile::getId():
        return WallPaperNoFile::read(reader);

    case InputReportReasonSpam::getId():
        return InputReportReasonSpam::read(reader);

    case InputReportReasonViolence::getId():
        return InputReportReasonViolence::read(reader);

    case InputReportReasonPornography::getId():
        return InputReportReasonPornography::read(reader);

    case InputReportReasonChildAbuse::getId():
        return InputReportReasonChildAbuse::read(reader);

    case InputReportReasonOther::getId():
        return InputReportReasonOther::read(reader);

    case InputReportReasonCopyright::getId():
        return InputReportReasonCopyright::read(reader);

    case InputReportReasonGeoIrrelevant::getId():
        return InputReportReasonGeoIrrelevant::read(reader);

    case InputReportReasonFake::getId():
        return InputReportReasonFake::read(reader);

    case UserFull::getId():
        return UserFull::read(reader);

    case Contact::getId():
        return Contact::read(reader);

    case ImportedContact::getId():
        return ImportedContact::read(reader);

    case ContactStatus::getId():
        return ContactStatus::read(reader);

    case contacts::ContactsNotModified::getId():
        return contacts::ContactsNotModified::read(reader);

    case contacts::Contacts::getId():
        return contacts::Contacts::read(reader);

    case contacts::ImportedContacts::getId():
        return contacts::ImportedContacts::read(reader);

    case contacts::Blocked::getId():
        return contacts::Blocked::read(reader);

    case contacts::BlockedSlice::getId():
        return contacts::BlockedSlice::read(reader);

    case messages::Dialogs::getId():
        return messages::Dialogs::read(reader);

    case messages::DialogsSlice::getId():
        return messages::DialogsSlice::read(reader);

    case messages::DialogsNotModified::getId():
        return messages::DialogsNotModified::read(reader);

    case messages::Messages::getId():
        return messages::Messages::read(reader);

    case messages::MessagesSlice::getId():
        return messages::MessagesSlice::read(reader);

    case messages::ChannelMessages::getId():
        return messages::ChannelMessages::read(reader);

    case messages::MessagesNotModified::getId():
        return messages::MessagesNotModified::read(reader);

    case messages::Chats::getId():
        return messages::Chats::read(reader);

    case messages::ChatsSlice::getId():
        return messages::ChatsSlice::read(reader);

    case messages::ChatFull::getId():
        return messages::ChatFull::read(reader);

    case messages::AffectedHistory::getId():
        return messages::AffectedHistory::read(reader);

    case InputMessagesFilterEmpty::getId():
        return InputMessagesFilterEmpty::read(reader);

    case InputMessagesFilterPhotos::getId():
        return InputMessagesFilterPhotos::read(reader);

    case InputMessagesFilterVideo::getId():
        return InputMessagesFilterVideo::read(reader);

    case InputMessagesFilterPhotoVideo::getId():
        return InputMessagesFilterPhotoVideo::read(reader);

    case InputMessagesFilterDocument::getId():
        return InputMessagesFilterDocument::read(reader);

    case InputMessagesFilterUrl::getId():
        return InputMessagesFilterUrl::read(reader);

    case InputMessagesFilterGif::getId():
        return InputMessagesFilterGif::read(reader);

    case InputMessagesFilterVoice::getId():
        return InputMessagesFilterVoice::read(reader);

    case InputMessagesFilterMusic::getId():
        return InputMessagesFilterMusic::read(reader);

    case InputMessagesFilterChatPhotos::getId():
        return InputMessagesFilterChatPhotos::read(reader);

    case InputMessagesFilterPhoneCalls::getId():
        return InputMessagesFilterPhoneCalls::read(reader);

    case InputMessagesFilterRoundVoice::getId():
        return InputMessagesFilterRoundVoice::read(reader);

    case InputMessagesFilterRoundVideo::getId():
        return InputMessagesFilterRoundVideo::read(reader);

    case InputMessagesFilterMyMentions::getId():
        return InputMessagesFilterMyMentions::read(reader);

    case InputMessagesFilterGeo::getId():
        return InputMessagesFilterGeo::read(reader);

    case InputMessagesFilterContacts::getId():
        return InputMessagesFilterContacts::read(reader);

    case InputMessagesFilterPinned::getId():
        return InputMessagesFilterPinned::read(reader);

    case UpdateNewMessage::getId():
        return UpdateNewMessage::read(reader);

    case UpdateMessageID::getId():
        return UpdateMessageID::read(reader);

    case UpdateDeleteMessages::getId():
        return UpdateDeleteMessages::read(reader);

    case UpdateUserTyping::getId():
        return UpdateUserTyping::read(reader);

    case UpdateChatUserTyping::getId():
        return UpdateChatUserTyping::read(reader);

    case UpdateChatParticipants::getId():
        return UpdateChatParticipants::read(reader);

    case UpdateUserStatus::getId():
        return UpdateUserStatus::read(reader);

    case UpdateUserName::getId():
        return UpdateUserName::read(reader);

    case UpdateUserPhoto::getId():
        return UpdateUserPhoto::read(reader);

    case UpdateNewEncryptedMessage::getId():
        return UpdateNewEncryptedMessage::read(reader);

    case UpdateEncryptedChatTyping::getId():
        return UpdateEncryptedChatTyping::read(reader);

    case UpdateEncryption::getId():
        return UpdateEncryption::read(reader);

    case UpdateEncryptedMessagesRead::getId():
        return UpdateEncryptedMessagesRead::read(reader);

    case UpdateChatParticipantAdd::getId():
        return UpdateChatParticipantAdd::read(reader);

    case UpdateChatParticipantDelete::getId():
        return UpdateChatParticipantDelete::read(reader);

    case UpdateDcOptions::getId():
        return UpdateDcOptions::read(reader);

    case UpdateNotifySettings::getId():
        return UpdateNotifySettings::read(reader);

    case UpdateServiceNotification::getId():
        return UpdateServiceNotification::read(reader);

    case UpdatePrivacy::getId():
        return UpdatePrivacy::read(reader);

    case UpdateUserPhone::getId():
        return UpdateUserPhone::read(reader);

    case UpdateReadHistoryInbox::getId():
        return UpdateReadHistoryInbox::read(reader);

    case UpdateReadHistoryOutbox::getId():
        return UpdateReadHistoryOutbox::read(reader);

    case UpdateWebPage::getId():
        return UpdateWebPage::read(reader);

    case UpdateReadMessagesContents::getId():
        return UpdateReadMessagesContents::read(reader);

    case UpdateChannelTooLong::getId():
        return UpdateChannelTooLong::read(reader);

    case UpdateChannel::getId():
        return UpdateChannel::read(reader);

    case UpdateNewChannelMessage::getId():
        return UpdateNewChannelMessage::read(reader);

    case UpdateReadChannelInbox::getId():
        return UpdateReadChannelInbox::read(reader);

    case UpdateDeleteChannelMessages::getId():
        return UpdateDeleteChannelMessages::read(reader);

    case UpdateChannelMessageViews::getId():
        return UpdateChannelMessageViews::read(reader);

    case UpdateChatParticipantAdmin::getId():
        return UpdateChatParticipantAdmin::read(reader);

    case UpdateNewStickerSet::getId():
        return UpdateNewStickerSet::read(reader);

    case UpdateStickerSetsOrder::getId():
        return UpdateStickerSetsOrder::read(reader);

    case UpdateStickerSets::getId():
        return UpdateStickerSets::read(reader);

    case UpdateSavedGifs::getId():
        return UpdateSavedGifs::read(reader);

    case UpdateBotInlineQuery::getId():
        return UpdateBotInlineQuery::read(reader);

    case UpdateBotInlineSend::getId():
        return UpdateBotInlineSend::read(reader);

    case UpdateEditChannelMessage::getId():
        return UpdateEditChannelMessage::read(reader);

    case UpdateBotCallbackQuery::getId():
        return UpdateBotCallbackQuery::read(reader);

    case UpdateEditMessage::getId():
        return UpdateEditMessage::read(reader);

    case UpdateInlineBotCallbackQuery::getId():
        return UpdateInlineBotCallbackQuery::read(reader);

    case UpdateReadChannelOutbox::getId():
        return UpdateReadChannelOutbox::read(reader);

    case UpdateDraftMessage::getId():
        return UpdateDraftMessage::read(reader);

    case UpdateReadFeaturedStickers::getId():
        return UpdateReadFeaturedStickers::read(reader);

    case UpdateRecentStickers::getId():
        return UpdateRecentStickers::read(reader);

    case UpdateConfig::getId():
        return UpdateConfig::read(reader);

    case UpdatePtsChanged::getId():
        return UpdatePtsChanged::read(reader);

    case UpdateChannelWebPage::getId():
        return UpdateChannelWebPage::read(reader);

    case UpdateDialogPinned::getId():
        return UpdateDialogPinned::read(reader);

    case UpdatePinnedDialogs::getId():
        return UpdatePinnedDialogs::read(reader);

    case UpdateBotWebhookJSON::getId():
        return UpdateBotWebhookJSON::read(reader);

    case UpdateBotWebhookJSONQuery::getId():
        return UpdateBotWebhookJSONQuery::read(reader);

    case UpdateBotShippingQuery::getId():
        return UpdateBotShippingQuery::read(reader);

    case UpdateBotPrecheckoutQuery::getId():
        return UpdateBotPrecheckoutQuery::read(reader);

    case UpdatePhoneCall::getId():
        return UpdatePhoneCall::read(reader);

    case UpdateLangPackTooLong::getId():
        return UpdateLangPackTooLong::read(reader);

    case UpdateLangPack::getId():
        return UpdateLangPack::read(reader);

    case UpdateFavedStickers::getId():
        return UpdateFavedStickers::read(reader);

    case UpdateChannelReadMessagesContents::getId():
        return UpdateChannelReadMessagesContents::read(reader);

    case UpdateContactsReset::getId():
        return UpdateContactsReset::read(reader);

    case UpdateChannelAvailableMessages::getId():
        return UpdateChannelAvailableMessages::read(reader);

    case UpdateDialogUnreadMark::getId():
        return UpdateDialogUnreadMark::read(reader);

    case UpdateMessagePoll::getId():
        return UpdateMessagePoll::read(reader);

    case UpdateChatDefaultBannedRights::getId():
        return UpdateChatDefaultBannedRights::read(reader);

    case UpdateFolderPeers::getId():
        return UpdateFolderPeers::read(reader);

    case UpdatePeerSettings::getId():
        return UpdatePeerSettings::read(reader);

    case UpdatePeerLocated::getId():
        return UpdatePeerLocated::read(reader);

    case UpdateNewScheduledMessage::getId():
        return UpdateNewScheduledMessage::read(reader);

    case UpdateDeleteScheduledMessages::getId():
        return UpdateDeleteScheduledMessages::read(reader);

    case UpdateTheme::getId():
        return UpdateTheme::read(reader);

    case UpdateGeoLiveViewed::getId():
        return UpdateGeoLiveViewed::read(reader);

    case UpdateLoginToken::getId():
        return UpdateLoginToken::read(reader);

    case UpdateMessagePollVote::getId():
        return UpdateMessagePollVote::read(reader);

    case UpdateDialogFilter::getId():
        return UpdateDialogFilter::read(reader);

    case UpdateDialogFilterOrder::getId():
        return UpdateDialogFilterOrder::read(reader);

    case UpdateDialogFilters::getId():
        return UpdateDialogFilters::read(reader);

    case UpdatePhoneCallSignalingData::getId():
        return UpdatePhoneCallSignalingData::read(reader);

    case UpdateChannelMessageForwards::getId():
        return UpdateChannelMessageForwards::read(reader);

    case UpdateReadChannelDiscussionInbox::getId():
        return UpdateReadChannelDiscussionInbox::read(reader);

    case UpdateReadChannelDiscussionOutbox::getId():
        return UpdateReadChannelDiscussionOutbox::read(reader);

    case UpdatePeerBlocked::getId():
        return UpdatePeerBlocked::read(reader);

    case UpdateChannelUserTyping::getId():
        return UpdateChannelUserTyping::read(reader);

    case UpdatePinnedMessages::getId():
        return UpdatePinnedMessages::read(reader);

    case UpdatePinnedChannelMessages::getId():
        return UpdatePinnedChannelMessages::read(reader);

    case UpdateChat::getId():
        return UpdateChat::read(reader);

    case UpdateGroupCallParticipants::getId():
        return UpdateGroupCallParticipants::read(reader);

    case UpdateGroupCall::getId():
        return UpdateGroupCall::read(reader);

    case UpdatePeerHistoryTTL::getId():
        return UpdatePeerHistoryTTL::read(reader);

    case UpdateChatParticipant::getId():
        return UpdateChatParticipant::read(reader);

    case UpdateChannelParticipant::getId():
        return UpdateChannelParticipant::read(reader);

    case UpdateBotStopped::getId():
        return UpdateBotStopped::read(reader);

    case UpdateGroupCallConnection::getId():
        return UpdateGroupCallConnection::read(reader);

    case updates::State::getId():
        return updates::State::read(reader);

    case updates::DifferenceEmpty::getId():
        return updates::DifferenceEmpty::read(reader);

    case updates::Difference::getId():
        return updates::Difference::read(reader);

    case updates::DifferenceSlice::getId():
        return updates::DifferenceSlice::read(reader);

    case updates::DifferenceTooLong::getId():
        return updates::DifferenceTooLong::read(reader);

    case UpdatesTooLong::getId():
        return UpdatesTooLong::read(reader);

    case UpdateShortMessage::getId():
        return UpdateShortMessage::read(reader);

    case UpdateShortChatMessage::getId():
        return UpdateShortChatMessage::read(reader);

    case UpdateShort::getId():
        return UpdateShort::read(reader);

    case UpdatesCombined::getId():
        return UpdatesCombined::read(reader);

    case Updates::getId():
        return Updates::read(reader);

    case UpdateShortSentMessage::getId():
        return UpdateShortSentMessage::read(reader);

    case photos::Photos::getId():
        return photos::Photos::read(reader);

    case photos::PhotosSlice::getId():
        return photos::PhotosSlice::read(reader);

    case photos::Photo::getId():
        return photos::Photo::read(reader);

    case upload::File::getId():
        return upload::File::read(reader);

    case upload::FileCdnRedirect::getId():
        return upload::FileCdnRedirect::read(reader);

    case DcOption::getId():
        return DcOption::read(reader);

    case Config::getId():
        return Config::read(reader);

    case NearestDc::getId():
        return NearestDc::read(reader);

    case help::AppUpdate::getId():
        return help::AppUpdate::read(reader);

    case help::NoAppUpdate::getId():
        return help::NoAppUpdate::read(reader);

    case help::InviteText::getId():
        return help::InviteText::read(reader);

    case EncryptedChatEmpty::getId():
        return EncryptedChatEmpty::read(reader);

    case EncryptedChatWaiting::getId():
        return EncryptedChatWaiting::read(reader);

    case EncryptedChatRequested::getId():
        return EncryptedChatRequested::read(reader);

    case EncryptedChat::getId():
        return EncryptedChat::read(reader);

    case EncryptedChatDiscarded::getId():
        return EncryptedChatDiscarded::read(reader);

    case InputEncryptedChat::getId():
        return InputEncryptedChat::read(reader);

    case EncryptedFileEmpty::getId():
        return EncryptedFileEmpty::read(reader);

    case EncryptedFile::getId():
        return EncryptedFile::read(reader);

    case InputEncryptedFileEmpty::getId():
        return InputEncryptedFileEmpty::read(reader);

    case InputEncryptedFileUploaded::getId():
        return InputEncryptedFileUploaded::read(reader);

    case InputEncryptedFile::getId():
        return InputEncryptedFile::read(reader);

    case InputEncryptedFileBigUploaded::getId():
        return InputEncryptedFileBigUploaded::read(reader);

    case EncryptedMessage::getId():
        return EncryptedMessage::read(reader);

    case EncryptedMessageService::getId():
        return EncryptedMessageService::read(reader);

    case messages::DhConfigNotModified::getId():
        return messages::DhConfigNotModified::read(reader);

    case messages::DhConfig::getId():
        return messages::DhConfig::read(reader);

    case messages::SentEncryptedMessage::getId():
        return messages::SentEncryptedMessage::read(reader);

    case messages::SentEncryptedFile::getId():
        return messages::SentEncryptedFile::read(reader);

    case InputDocumentEmpty::getId():
        return InputDocumentEmpty::read(reader);

    case InputDocument::getId():
        return InputDocument::read(reader);

    case DocumentEmpty::getId():
        return DocumentEmpty::read(reader);

    case Document::getId():
        return Document::read(reader);

    case help::Support::getId():
        return help::Support::read(reader);

    case NotifyPeer::getId():
        return NotifyPeer::read(reader);

    case NotifyUsers::getId():
        return NotifyUsers::read(reader);

    case NotifyChats::getId():
        return NotifyChats::read(reader);

    case NotifyBroadcasts::getId():
        return NotifyBroadcasts::read(reader);

    case SendMessageTypingAction::getId():
        return SendMessageTypingAction::read(reader);

    case SendMessageCancelAction::getId():
        return SendMessageCancelAction::read(reader);

    case SendMessageRecordVideoAction::getId():
        return SendMessageRecordVideoAction::read(reader);

    case SendMessageUploadVideoAction::getId():
        return SendMessageUploadVideoAction::read(reader);

    case SendMessageRecordAudioAction::getId():
        return SendMessageRecordAudioAction::read(reader);

    case SendMessageUploadAudioAction::getId():
        return SendMessageUploadAudioAction::read(reader);

    case SendMessageUploadPhotoAction::getId():
        return SendMessageUploadPhotoAction::read(reader);

    case SendMessageUploadDocumentAction::getId():
        return SendMessageUploadDocumentAction::read(reader);

    case SendMessageGeoLocationAction::getId():
        return SendMessageGeoLocationAction::read(reader);

    case SendMessageChooseContactAction::getId():
        return SendMessageChooseContactAction::read(reader);

    case SendMessageGamePlayAction::getId():
        return SendMessageGamePlayAction::read(reader);

    case SendMessageRecordRoundAction::getId():
        return SendMessageRecordRoundAction::read(reader);

    case SendMessageUploadRoundAction::getId():
        return SendMessageUploadRoundAction::read(reader);

    case SpeakingInGroupCallAction::getId():
        return SpeakingInGroupCallAction::read(reader);

    case SendMessageHistoryImportAction::getId():
        return SendMessageHistoryImportAction::read(reader);

    case contacts::Found::getId():
        return contacts::Found::read(reader);

    case InputPrivacyKeyStatusTimestamp::getId():
        return InputPrivacyKeyStatusTimestamp::read(reader);

    case InputPrivacyKeyChatInvite::getId():
        return InputPrivacyKeyChatInvite::read(reader);

    case InputPrivacyKeyPhoneCall::getId():
        return InputPrivacyKeyPhoneCall::read(reader);

    case InputPrivacyKeyPhoneP2P::getId():
        return InputPrivacyKeyPhoneP2P::read(reader);

    case InputPrivacyKeyForwards::getId():
        return InputPrivacyKeyForwards::read(reader);

    case InputPrivacyKeyProfilePhoto::getId():
        return InputPrivacyKeyProfilePhoto::read(reader);

    case InputPrivacyKeyPhoneNumber::getId():
        return InputPrivacyKeyPhoneNumber::read(reader);

    case InputPrivacyKeyAddedByPhone::getId():
        return InputPrivacyKeyAddedByPhone::read(reader);

    case PrivacyKeyStatusTimestamp::getId():
        return PrivacyKeyStatusTimestamp::read(reader);

    case PrivacyKeyChatInvite::getId():
        return PrivacyKeyChatInvite::read(reader);

    case PrivacyKeyPhoneCall::getId():
        return PrivacyKeyPhoneCall::read(reader);

    case PrivacyKeyPhoneP2P::getId():
        return PrivacyKeyPhoneP2P::read(reader);

    case PrivacyKeyForwards::getId():
        return PrivacyKeyForwards::read(reader);

    case PrivacyKeyProfilePhoto::getId():
        return PrivacyKeyProfilePhoto::read(reader);

    case PrivacyKeyPhoneNumber::getId():
        return PrivacyKeyPhoneNumber::read(reader);

    case PrivacyKeyAddedByPhone::getId():
        return PrivacyKeyAddedByPhone::read(reader);

    case InputPrivacyValueAllowContacts::getId():
        return InputPrivacyValueAllowContacts::read(reader);

    case InputPrivacyValueAllowAll::getId():
        return InputPrivacyValueAllowAll::read(reader);

    case InputPrivacyValueAllowUsers::getId():
        return InputPrivacyValueAllowUsers::read(reader);

    case InputPrivacyValueDisallowContacts::getId():
        return InputPrivacyValueDisallowContacts::read(reader);

    case InputPrivacyValueDisallowAll::getId():
        return InputPrivacyValueDisallowAll::read(reader);

    case InputPrivacyValueDisallowUsers::getId():
        return InputPrivacyValueDisallowUsers::read(reader);

    case InputPrivacyValueAllowChatParticipants::getId():
        return InputPrivacyValueAllowChatParticipants::read(reader);

    case InputPrivacyValueDisallowChatParticipants::getId():
        return InputPrivacyValueDisallowChatParticipants::read(reader);

    case PrivacyValueAllowContacts::getId():
        return PrivacyValueAllowContacts::read(reader);

    case PrivacyValueAllowAll::getId():
        return PrivacyValueAllowAll::read(reader);

    case PrivacyValueAllowUsers::getId():
        return PrivacyValueAllowUsers::read(reader);

    case PrivacyValueDisallowContacts::getId():
        return PrivacyValueDisallowContacts::read(reader);

    case PrivacyValueDisallowAll::getId():
        return PrivacyValueDisallowAll::read(reader);

    case PrivacyValueDisallowUsers::getId():
        return PrivacyValueDisallowUsers::read(reader);

    case PrivacyValueAllowChatParticipants::getId():
        return PrivacyValueAllowChatParticipants::read(reader);

    case PrivacyValueDisallowChatParticipants::getId():
        return PrivacyValueDisallowChatParticipants::read(reader);

    case account::PrivacyRules::getId():
        return account::PrivacyRules::read(reader);

    case AccountDaysTTL::getId():
        return AccountDaysTTL::read(reader);

    case DocumentAttributeImageSize::getId():
        return DocumentAttributeImageSize::read(reader);

    case DocumentAttributeAnimated::getId():
        return DocumentAttributeAnimated::read(reader);

    case DocumentAttributeSticker::getId():
        return DocumentAttributeSticker::read(reader);

    case DocumentAttributeVideo::getId():
        return DocumentAttributeVideo::read(reader);

    case DocumentAttributeAudio::getId():
        return DocumentAttributeAudio::read(reader);

    case DocumentAttributeFilename::getId():
        return DocumentAttributeFilename::read(reader);

    case DocumentAttributeHasStickers::getId():
        return DocumentAttributeHasStickers::read(reader);

    case messages::StickersNotModified::getId():
        return messages::StickersNotModified::read(reader);

    case messages::Stickers::getId():
        return messages::Stickers::read(reader);

    case StickerPack::getId():
        return StickerPack::read(reader);

    case messages::AllStickersNotModified::getId():
        return messages::AllStickersNotModified::read(reader);

    case messages::AllStickers::getId():
        return messages::AllStickers::read(reader);

    case messages::AffectedMessages::getId():
        return messages::AffectedMessages::read(reader);

    case WebPageEmpty::getId():
        return WebPageEmpty::read(reader);

    case WebPagePending::getId():
        return WebPagePending::read(reader);

    case WebPage::getId():
        return WebPage::read(reader);

    case WebPageNotModified::getId():
        return WebPageNotModified::read(reader);

    case Authorization::getId():
        return Authorization::read(reader);

    case account::Authorizations::getId():
        return account::Authorizations::read(reader);

    case account::Password::getId():
        return account::Password::read(reader);

    case account::PasswordSettings::getId():
        return account::PasswordSettings::read(reader);

    case account::PasswordInputSettings::getId():
        return account::PasswordInputSettings::read(reader);

    case auth::PasswordRecovery::getId():
        return auth::PasswordRecovery::read(reader);

    case ReceivedNotifyMessage::getId():
        return ReceivedNotifyMessage::read(reader);

    case ChatInviteExported::getId():
        return ChatInviteExported::read(reader);

    case ChatInviteAlready::getId():
        return ChatInviteAlready::read(reader);

    case ChatInvite::getId():
        return ChatInvite::read(reader);

    case ChatInvitePeek::getId():
        return ChatInvitePeek::read(reader);

    case InputStickerSetEmpty::getId():
        return InputStickerSetEmpty::read(reader);

    case InputStickerSetID::getId():
        return InputStickerSetID::read(reader);

    case InputStickerSetShortName::getId():
        return InputStickerSetShortName::read(reader);

    case InputStickerSetAnimatedEmoji::getId():
        return InputStickerSetAnimatedEmoji::read(reader);

    case InputStickerSetDice::getId():
        return InputStickerSetDice::read(reader);

    case StickerSet::getId():
        return StickerSet::read(reader);

    case messages::StickerSet::getId():
        return messages::StickerSet::read(reader);

    case BotCommand::getId():
        return BotCommand::read(reader);

    case BotInfo::getId():
        return BotInfo::read(reader);

    case KeyboardButton::getId():
        return KeyboardButton::read(reader);

    case KeyboardButtonUrl::getId():
        return KeyboardButtonUrl::read(reader);

    case KeyboardButtonCallback::getId():
        return KeyboardButtonCallback::read(reader);

    case KeyboardButtonRequestPhone::getId():
        return KeyboardButtonRequestPhone::read(reader);

    case KeyboardButtonRequestGeoLocation::getId():
        return KeyboardButtonRequestGeoLocation::read(reader);

    case KeyboardButtonSwitchInline::getId():
        return KeyboardButtonSwitchInline::read(reader);

    case KeyboardButtonGame::getId():
        return KeyboardButtonGame::read(reader);

    case KeyboardButtonBuy::getId():
        return KeyboardButtonBuy::read(reader);

    case KeyboardButtonUrlAuth::getId():
        return KeyboardButtonUrlAuth::read(reader);

    case InputKeyboardButtonUrlAuth::getId():
        return InputKeyboardButtonUrlAuth::read(reader);

    case KeyboardButtonRequestPoll::getId():
        return KeyboardButtonRequestPoll::read(reader);

    case KeyboardButtonRow::getId():
        return KeyboardButtonRow::read(reader);

    case ReplyKeyboardHide::getId():
        return ReplyKeyboardHide::read(reader);

    case ReplyKeyboardForceReply::getId():
        return ReplyKeyboardForceReply::read(reader);

    case ReplyKeyboardMarkup::getId():
        return ReplyKeyboardMarkup::read(reader);

    case ReplyInlineMarkup::getId():
        return ReplyInlineMarkup::read(reader);

    case MessageEntityUnknown::getId():
        return MessageEntityUnknown::read(reader);

    case MessageEntityMention::getId():
        return MessageEntityMention::read(reader);

    case MessageEntityHashtag::getId():
        return MessageEntityHashtag::read(reader);

    case MessageEntityBotCommand::getId():
        return MessageEntityBotCommand::read(reader);

    case MessageEntityUrl::getId():
        return MessageEntityUrl::read(reader);

    case MessageEntityEmail::getId():
        return MessageEntityEmail::read(reader);

    case MessageEntityBold::getId():
        return MessageEntityBold::read(reader);

    case MessageEntityItalic::getId():
        return MessageEntityItalic::read(reader);

    case MessageEntityCode::getId():
        return MessageEntityCode::read(reader);

    case MessageEntityPre::getId():
        return MessageEntityPre::read(reader);

    case MessageEntityTextUrl::getId():
        return MessageEntityTextUrl::read(reader);

    case MessageEntityMentionName::getId():
        return MessageEntityMentionName::read(reader);

    case InputMessageEntityMentionName::getId():
        return InputMessageEntityMentionName::read(reader);

    case MessageEntityPhone::getId():
        return MessageEntityPhone::read(reader);

    case MessageEntityCashtag::getId():
        return MessageEntityCashtag::read(reader);

    case MessageEntityUnderline::getId():
        return MessageEntityUnderline::read(reader);

    case MessageEntityStrike::getId():
        return MessageEntityStrike::read(reader);

    case MessageEntityBlockquote::getId():
        return MessageEntityBlockquote::read(reader);

    case MessageEntityBankCard::getId():
        return MessageEntityBankCard::read(reader);

    case InputChannelEmpty::getId():
        return InputChannelEmpty::read(reader);

    case InputChannel::getId():
        return InputChannel::read(reader);

    case InputChannelFromMessage::getId():
        return InputChannelFromMessage::read(reader);

    case contacts::ResolvedPeer::getId():
        return contacts::ResolvedPeer::read(reader);

    case MessageRange::getId():
        return MessageRange::read(reader);

    case updates::ChannelDifferenceEmpty::getId():
        return updates::ChannelDifferenceEmpty::read(reader);

    case updates::ChannelDifferenceTooLong::getId():
        return updates::ChannelDifferenceTooLong::read(reader);

    case updates::ChannelDifference::getId():
        return updates::ChannelDifference::read(reader);

    case ChannelMessagesFilterEmpty::getId():
        return ChannelMessagesFilterEmpty::read(reader);

    case ChannelMessagesFilter::getId():
        return ChannelMessagesFilter::read(reader);

    case ChannelParticipant::getId():
        return ChannelParticipant::read(reader);

    case ChannelParticipantSelf::getId():
        return ChannelParticipantSelf::read(reader);

    case ChannelParticipantCreator::getId():
        return ChannelParticipantCreator::read(reader);

    case ChannelParticipantAdmin::getId():
        return ChannelParticipantAdmin::read(reader);

    case ChannelParticipantBanned::getId():
        return ChannelParticipantBanned::read(reader);

    case ChannelParticipantLeft::getId():
        return ChannelParticipantLeft::read(reader);

    case ChannelParticipantsRecent::getId():
        return ChannelParticipantsRecent::read(reader);

    case ChannelParticipantsAdmins::getId():
        return ChannelParticipantsAdmins::read(reader);

    case ChannelParticipantsKicked::getId():
        return ChannelParticipantsKicked::read(reader);

    case ChannelParticipantsBots::getId():
        return ChannelParticipantsBots::read(reader);

    case ChannelParticipantsBanned::getId():
        return ChannelParticipantsBanned::read(reader);

    case ChannelParticipantsSearch::getId():
        return ChannelParticipantsSearch::read(reader);

    case ChannelParticipantsContacts::getId():
        return ChannelParticipantsContacts::read(reader);

    case ChannelParticipantsMentions::getId():
        return ChannelParticipantsMentions::read(reader);

    case channels::ChannelParticipants::getId():
        return channels::ChannelParticipants::read(reader);

    case channels::ChannelParticipantsNotModified::getId():
        return channels::ChannelParticipantsNotModified::read(reader);

    case channels::ChannelParticipant::getId():
        return channels::ChannelParticipant::read(reader);

    case help::TermsOfService::getId():
        return help::TermsOfService::read(reader);

    case messages::SavedGifsNotModified::getId():
        return messages::SavedGifsNotModified::read(reader);

    case messages::SavedGifs::getId():
        return messages::SavedGifs::read(reader);

    case InputBotInlineMessageMediaAuto::getId():
        return InputBotInlineMessageMediaAuto::read(reader);

    case InputBotInlineMessageText::getId():
        return InputBotInlineMessageText::read(reader);

    case InputBotInlineMessageMediaGeo::getId():
        return InputBotInlineMessageMediaGeo::read(reader);

    case InputBotInlineMessageMediaVenue::getId():
        return InputBotInlineMessageMediaVenue::read(reader);

    case InputBotInlineMessageMediaContact::getId():
        return InputBotInlineMessageMediaContact::read(reader);

    case InputBotInlineMessageGame::getId():
        return InputBotInlineMessageGame::read(reader);

    case InputBotInlineMessageMediaInvoice::getId():
        return InputBotInlineMessageMediaInvoice::read(reader);

    case InputBotInlineResult::getId():
        return InputBotInlineResult::read(reader);

    case InputBotInlineResultPhoto::getId():
        return InputBotInlineResultPhoto::read(reader);

    case InputBotInlineResultDocument::getId():
        return InputBotInlineResultDocument::read(reader);

    case InputBotInlineResultGame::getId():
        return InputBotInlineResultGame::read(reader);

    case BotInlineMessageMediaAuto::getId():
        return BotInlineMessageMediaAuto::read(reader);

    case BotInlineMessageText::getId():
        return BotInlineMessageText::read(reader);

    case BotInlineMessageMediaGeo::getId():
        return BotInlineMessageMediaGeo::read(reader);

    case BotInlineMessageMediaVenue::getId():
        return BotInlineMessageMediaVenue::read(reader);

    case BotInlineMessageMediaContact::getId():
        return BotInlineMessageMediaContact::read(reader);

    case BotInlineMessageMediaInvoice::getId():
        return BotInlineMessageMediaInvoice::read(reader);

    case BotInlineResult::getId():
        return BotInlineResult::read(reader);

    case BotInlineMediaResult::getId():
        return BotInlineMediaResult::read(reader);

    case messages::BotResults::getId():
        return messages::BotResults::read(reader);

    case ExportedMessageLink::getId():
        return ExportedMessageLink::read(reader);

    case MessageFwdHeader::getId():
        return MessageFwdHeader::read(reader);

    case auth::CodeTypeSms::getId():
        return auth::CodeTypeSms::read(reader);

    case auth::CodeTypeCall::getId():
        return auth::CodeTypeCall::read(reader);

    case auth::CodeTypeFlashCall::getId():
        return auth::CodeTypeFlashCall::read(reader);

    case auth::SentCodeTypeApp::getId():
        return auth::SentCodeTypeApp::read(reader);

    case auth::SentCodeTypeSms::getId():
        return auth::SentCodeTypeSms::read(reader);

    case auth::SentCodeTypeCall::getId():
        return auth::SentCodeTypeCall::read(reader);

    case auth::SentCodeTypeFlashCall::getId():
        return auth::SentCodeTypeFlashCall::read(reader);

    case messages::BotCallbackAnswer::getId():
        return messages::BotCallbackAnswer::read(reader);

    case messages::MessageEditData::getId():
        return messages::MessageEditData::read(reader);

    case InputBotInlineMessageID::getId():
        return InputBotInlineMessageID::read(reader);

    case InlineBotSwitchPM::getId():
        return InlineBotSwitchPM::read(reader);

    case messages::PeerDialogs::getId():
        return messages::PeerDialogs::read(reader);

    case TopPeer::getId():
        return TopPeer::read(reader);

    case TopPeerCategoryBotsPM::getId():
        return TopPeerCategoryBotsPM::read(reader);

    case TopPeerCategoryBotsInline::getId():
        return TopPeerCategoryBotsInline::read(reader);

    case TopPeerCategoryCorrespondents::getId():
        return TopPeerCategoryCorrespondents::read(reader);

    case TopPeerCategoryGroups::getId():
        return TopPeerCategoryGroups::read(reader);

    case TopPeerCategoryChannels::getId():
        return TopPeerCategoryChannels::read(reader);

    case TopPeerCategoryPhoneCalls::getId():
        return TopPeerCategoryPhoneCalls::read(reader);

    case TopPeerCategoryForwardUsers::getId():
        return TopPeerCategoryForwardUsers::read(reader);

    case TopPeerCategoryForwardChats::getId():
        return TopPeerCategoryForwardChats::read(reader);

    case TopPeerCategoryPeers::getId():
        return TopPeerCategoryPeers::read(reader);

    case contacts::TopPeersNotModified::getId():
        return contacts::TopPeersNotModified::read(reader);

    case contacts::TopPeers::getId():
        return contacts::TopPeers::read(reader);

    case contacts::TopPeersDisabled::getId():
        return contacts::TopPeersDisabled::read(reader);

    case DraftMessageEmpty::getId():
        return DraftMessageEmpty::read(reader);

    case DraftMessage::getId():
        return DraftMessage::read(reader);

    case messages::FeaturedStickersNotModified::getId():
        return messages::FeaturedStickersNotModified::read(reader);

    case messages::FeaturedStickers::getId():
        return messages::FeaturedStickers::read(reader);

    case messages::RecentStickersNotModified::getId():
        return messages::RecentStickersNotModified::read(reader);

    case messages::RecentStickers::getId():
        return messages::RecentStickers::read(reader);

    case messages::ArchivedStickers::getId():
        return messages::ArchivedStickers::read(reader);

    case messages::StickerSetInstallResultSuccess::getId():
        return messages::StickerSetInstallResultSuccess::read(reader);

    case messages::StickerSetInstallResultArchive::getId():
        return messages::StickerSetInstallResultArchive::read(reader);

    case StickerSetCovered::getId():
        return StickerSetCovered::read(reader);

    case StickerSetMultiCovered::getId():
        return StickerSetMultiCovered::read(reader);

    case MaskCoords::getId():
        return MaskCoords::read(reader);

    case InputStickeredMediaPhoto::getId():
        return InputStickeredMediaPhoto::read(reader);

    case InputStickeredMediaDocument::getId():
        return InputStickeredMediaDocument::read(reader);

    case Game::getId():
        return Game::read(reader);

    case InputGameID::getId():
        return InputGameID::read(reader);

    case InputGameShortName::getId():
        return InputGameShortName::read(reader);

    case HighScore::getId():
        return HighScore::read(reader);

    case messages::HighScores::getId():
        return messages::HighScores::read(reader);

    case TextEmpty::getId():
        return TextEmpty::read(reader);

    case TextPlain::getId():
        return TextPlain::read(reader);

    case TextBold::getId():
        return TextBold::read(reader);

    case TextItalic::getId():
        return TextItalic::read(reader);

    case TextUnderline::getId():
        return TextUnderline::read(reader);

    case TextStrike::getId():
        return TextStrike::read(reader);

    case TextFixed::getId():
        return TextFixed::read(reader);

    case TextUrl::getId():
        return TextUrl::read(reader);

    case TextEmail::getId():
        return TextEmail::read(reader);

    case TextConcat::getId():
        return TextConcat::read(reader);

    case TextSubscript::getId():
        return TextSubscript::read(reader);

    case TextSuperscript::getId():
        return TextSuperscript::read(reader);

    case TextMarked::getId():
        return TextMarked::read(reader);

    case TextPhone::getId():
        return TextPhone::read(reader);

    case TextImage::getId():
        return TextImage::read(reader);

    case TextAnchor::getId():
        return TextAnchor::read(reader);

    case PageBlockUnsupported::getId():
        return PageBlockUnsupported::read(reader);

    case PageBlockTitle::getId():
        return PageBlockTitle::read(reader);

    case PageBlockSubtitle::getId():
        return PageBlockSubtitle::read(reader);

    case PageBlockAuthorDate::getId():
        return PageBlockAuthorDate::read(reader);

    case PageBlockHeader::getId():
        return PageBlockHeader::read(reader);

    case PageBlockSubheader::getId():
        return PageBlockSubheader::read(reader);

    case PageBlockParagraph::getId():
        return PageBlockParagraph::read(reader);

    case PageBlockPreformatted::getId():
        return PageBlockPreformatted::read(reader);

    case PageBlockFooter::getId():
        return PageBlockFooter::read(reader);

    case PageBlockDivider::getId():
        return PageBlockDivider::read(reader);

    case PageBlockAnchor::getId():
        return PageBlockAnchor::read(reader);

    case PageBlockList::getId():
        return PageBlockList::read(reader);

    case PageBlockBlockquote::getId():
        return PageBlockBlockquote::read(reader);

    case PageBlockPullquote::getId():
        return PageBlockPullquote::read(reader);

    case PageBlockPhoto::getId():
        return PageBlockPhoto::read(reader);

    case PageBlockVideo::getId():
        return PageBlockVideo::read(reader);

    case PageBlockCover::getId():
        return PageBlockCover::read(reader);

    case PageBlockEmbed::getId():
        return PageBlockEmbed::read(reader);

    case PageBlockEmbedPost::getId():
        return PageBlockEmbedPost::read(reader);

    case PageBlockCollage::getId():
        return PageBlockCollage::read(reader);

    case PageBlockSlideshow::getId():
        return PageBlockSlideshow::read(reader);

    case PageBlockChannel::getId():
        return PageBlockChannel::read(reader);

    case PageBlockAudio::getId():
        return PageBlockAudio::read(reader);

    case PageBlockKicker::getId():
        return PageBlockKicker::read(reader);

    case PageBlockTable::getId():
        return PageBlockTable::read(reader);

    case PageBlockOrderedList::getId():
        return PageBlockOrderedList::read(reader);

    case PageBlockDetails::getId():
        return PageBlockDetails::read(reader);

    case PageBlockRelatedArticles::getId():
        return PageBlockRelatedArticles::read(reader);

    case PageBlockMap::getId():
        return PageBlockMap::read(reader);

    case PhoneCallDiscardReasonMissed::getId():
        return PhoneCallDiscardReasonMissed::read(reader);

    case PhoneCallDiscardReasonDisconnect::getId():
        return PhoneCallDiscardReasonDisconnect::read(reader);

    case PhoneCallDiscardReasonHangup::getId():
        return PhoneCallDiscardReasonHangup::read(reader);

    case PhoneCallDiscardReasonBusy::getId():
        return PhoneCallDiscardReasonBusy::read(reader);

    case DataJSON::getId():
        return DataJSON::read(reader);

    case LabeledPrice::getId():
        return LabeledPrice::read(reader);

    case Invoice::getId():
        return Invoice::read(reader);

    case PaymentCharge::getId():
        return PaymentCharge::read(reader);

    case PostAddress::getId():
        return PostAddress::read(reader);

    case PaymentRequestedInfo::getId():
        return PaymentRequestedInfo::read(reader);

    case PaymentSavedCredentialsCard::getId():
        return PaymentSavedCredentialsCard::read(reader);

    case WebDocument::getId():
        return WebDocument::read(reader);

    case WebDocumentNoProxy::getId():
        return WebDocumentNoProxy::read(reader);

    case InputWebDocument::getId():
        return InputWebDocument::read(reader);

    case InputWebFileLocation::getId():
        return InputWebFileLocation::read(reader);

    case InputWebFileGeoPointLocation::getId():
        return InputWebFileGeoPointLocation::read(reader);

    case upload::WebFile::getId():
        return upload::WebFile::read(reader);

    case payments::PaymentForm::getId():
        return payments::PaymentForm::read(reader);

    case payments::ValidatedRequestedInfo::getId():
        return payments::ValidatedRequestedInfo::read(reader);

    case payments::PaymentResult::getId():
        return payments::PaymentResult::read(reader);

    case payments::PaymentVerificationNeeded::getId():
        return payments::PaymentVerificationNeeded::read(reader);

    case payments::PaymentReceipt::getId():
        return payments::PaymentReceipt::read(reader);

    case payments::SavedInfo::getId():
        return payments::SavedInfo::read(reader);

    case InputPaymentCredentialsSaved::getId():
        return InputPaymentCredentialsSaved::read(reader);

    case InputPaymentCredentials::getId():
        return InputPaymentCredentials::read(reader);

    case InputPaymentCredentialsApplePay::getId():
        return InputPaymentCredentialsApplePay::read(reader);

    case InputPaymentCredentialsGooglePay::getId():
        return InputPaymentCredentialsGooglePay::read(reader);

    case account::TmpPassword::getId():
        return account::TmpPassword::read(reader);

    case ShippingOption::getId():
        return ShippingOption::read(reader);

    case InputStickerSetItem::getId():
        return InputStickerSetItem::read(reader);

    case InputPhoneCall::getId():
        return InputPhoneCall::read(reader);

    case PhoneCallEmpty::getId():
        return PhoneCallEmpty::read(reader);

    case PhoneCallWaiting::getId():
        return PhoneCallWaiting::read(reader);

    case PhoneCallRequested::getId():
        return PhoneCallRequested::read(reader);

    case PhoneCallAccepted::getId():
        return PhoneCallAccepted::read(reader);

    case PhoneCall::getId():
        return PhoneCall::read(reader);

    case PhoneCallDiscarded::getId():
        return PhoneCallDiscarded::read(reader);

    case PhoneConnection::getId():
        return PhoneConnection::read(reader);

    case PhoneConnectionWebrtc::getId():
        return PhoneConnectionWebrtc::read(reader);

    case PhoneCallProtocol::getId():
        return PhoneCallProtocol::read(reader);

    case phone::PhoneCall::getId():
        return phone::PhoneCall::read(reader);

    case upload::CdnFileReuploadNeeded::getId():
        return upload::CdnFileReuploadNeeded::read(reader);

    case upload::CdnFile::getId():
        return upload::CdnFile::read(reader);

    case CdnPublicKey::getId():
        return CdnPublicKey::read(reader);

    case CdnConfig::getId():
        return CdnConfig::read(reader);

    case LangPackString::getId():
        return LangPackString::read(reader);

    case LangPackStringPluralized::getId():
        return LangPackStringPluralized::read(reader);

    case LangPackStringDeleted::getId():
        return LangPackStringDeleted::read(reader);

    case LangPackDifference::getId():
        return LangPackDifference::read(reader);

    case LangPackLanguage::getId():
        return LangPackLanguage::read(reader);

    case ChannelAdminLogEventActionChangeTitle::getId():
        return ChannelAdminLogEventActionChangeTitle::read(reader);

    case ChannelAdminLogEventActionChangeAbout::getId():
        return ChannelAdminLogEventActionChangeAbout::read(reader);

    case ChannelAdminLogEventActionChangeUsername::getId():
        return ChannelAdminLogEventActionChangeUsername::read(reader);

    case ChannelAdminLogEventActionChangePhoto::getId():
        return ChannelAdminLogEventActionChangePhoto::read(reader);

    case ChannelAdminLogEventActionToggleInvites::getId():
        return ChannelAdminLogEventActionToggleInvites::read(reader);

    case ChannelAdminLogEventActionToggleSignatures::getId():
        return ChannelAdminLogEventActionToggleSignatures::read(reader);

    case ChannelAdminLogEventActionUpdatePinned::getId():
        return ChannelAdminLogEventActionUpdatePinned::read(reader);

    case ChannelAdminLogEventActionEditMessage::getId():
        return ChannelAdminLogEventActionEditMessage::read(reader);

    case ChannelAdminLogEventActionDeleteMessage::getId():
        return ChannelAdminLogEventActionDeleteMessage::read(reader);

    case ChannelAdminLogEventActionParticipantJoin::getId():
        return ChannelAdminLogEventActionParticipantJoin::read(reader);

    case ChannelAdminLogEventActionParticipantLeave::getId():
        return ChannelAdminLogEventActionParticipantLeave::read(reader);

    case ChannelAdminLogEventActionParticipantInvite::getId():
        return ChannelAdminLogEventActionParticipantInvite::read(reader);

    case ChannelAdminLogEventActionParticipantToggleBan::getId():
        return ChannelAdminLogEventActionParticipantToggleBan::read(reader);

    case ChannelAdminLogEventActionParticipantToggleAdmin::getId():
        return ChannelAdminLogEventActionParticipantToggleAdmin::read(reader);

    case ChannelAdminLogEventActionChangeStickerSet::getId():
        return ChannelAdminLogEventActionChangeStickerSet::read(reader);

    case ChannelAdminLogEventActionTogglePreHistoryHidden::getId():
        return ChannelAdminLogEventActionTogglePreHistoryHidden::read(reader);

    case ChannelAdminLogEventActionDefaultBannedRights::getId():
        return ChannelAdminLogEventActionDefaultBannedRights::read(reader);

    case ChannelAdminLogEventActionStopPoll::getId():
        return ChannelAdminLogEventActionStopPoll::read(reader);

    case ChannelAdminLogEventActionChangeLinkedChat::getId():
        return ChannelAdminLogEventActionChangeLinkedChat::read(reader);

    case ChannelAdminLogEventActionChangeLocation::getId():
        return ChannelAdminLogEventActionChangeLocation::read(reader);

    case ChannelAdminLogEventActionToggleSlowMode::getId():
        return ChannelAdminLogEventActionToggleSlowMode::read(reader);

    case ChannelAdminLogEventActionStartGroupCall::getId():
        return ChannelAdminLogEventActionStartGroupCall::read(reader);

    case ChannelAdminLogEventActionDiscardGroupCall::getId():
        return ChannelAdminLogEventActionDiscardGroupCall::read(reader);

    case ChannelAdminLogEventActionParticipantMute::getId():
        return ChannelAdminLogEventActionParticipantMute::read(reader);

    case ChannelAdminLogEventActionParticipantUnmute::getId():
        return ChannelAdminLogEventActionParticipantUnmute::read(reader);

    case ChannelAdminLogEventActionToggleGroupCallSetting::getId():
        return ChannelAdminLogEventActionToggleGroupCallSetting::read(reader);

    case ChannelAdminLogEventActionParticipantJoinByInvite::getId():
        return ChannelAdminLogEventActionParticipantJoinByInvite::read(reader);

    case ChannelAdminLogEventActionExportedInviteDelete::getId():
        return ChannelAdminLogEventActionExportedInviteDelete::read(reader);

    case ChannelAdminLogEventActionExportedInviteRevoke::getId():
        return ChannelAdminLogEventActionExportedInviteRevoke::read(reader);

    case ChannelAdminLogEventActionExportedInviteEdit::getId():
        return ChannelAdminLogEventActionExportedInviteEdit::read(reader);

    case ChannelAdminLogEventActionParticipantVolume::getId():
        return ChannelAdminLogEventActionParticipantVolume::read(reader);

    case ChannelAdminLogEventActionChangeHistoryTTL::getId():
        return ChannelAdminLogEventActionChangeHistoryTTL::read(reader);

    case ChannelAdminLogEvent::getId():
        return ChannelAdminLogEvent::read(reader);

    case channels::AdminLogResults::getId():
        return channels::AdminLogResults::read(reader);

    case ChannelAdminLogEventsFilter::getId():
        return ChannelAdminLogEventsFilter::read(reader);

    case PopularContact::getId():
        return PopularContact::read(reader);

    case messages::FavedStickersNotModified::getId():
        return messages::FavedStickersNotModified::read(reader);

    case messages::FavedStickers::getId():
        return messages::FavedStickers::read(reader);

    case RecentMeUrlUnknown::getId():
        return RecentMeUrlUnknown::read(reader);

    case RecentMeUrlUser::getId():
        return RecentMeUrlUser::read(reader);

    case RecentMeUrlChat::getId():
        return RecentMeUrlChat::read(reader);

    case RecentMeUrlChatInvite::getId():
        return RecentMeUrlChatInvite::read(reader);

    case RecentMeUrlStickerSet::getId():
        return RecentMeUrlStickerSet::read(reader);

    case help::RecentMeUrls::getId():
        return help::RecentMeUrls::read(reader);

    case InputSingleMedia::getId():
        return InputSingleMedia::read(reader);

    case WebAuthorization::getId():
        return WebAuthorization::read(reader);

    case account::WebAuthorizations::getId():
        return account::WebAuthorizations::read(reader);

    case InputMessageID::getId():
        return InputMessageID::read(reader);

    case InputMessageReplyTo::getId():
        return InputMessageReplyTo::read(reader);

    case InputMessagePinned::getId():
        return InputMessagePinned::read(reader);

    case InputMessageCallbackQuery::getId():
        return InputMessageCallbackQuery::read(reader);

    case InputDialogPeer::getId():
        return InputDialogPeer::read(reader);

    case InputDialogPeerFolder::getId():
        return InputDialogPeerFolder::read(reader);

    case DialogPeer::getId():
        return DialogPeer::read(reader);

    case DialogPeerFolder::getId():
        return DialogPeerFolder::read(reader);

    case messages::FoundStickerSetsNotModified::getId():
        return messages::FoundStickerSetsNotModified::read(reader);

    case messages::FoundStickerSets::getId():
        return messages::FoundStickerSets::read(reader);

    case FileHash::getId():
        return FileHash::read(reader);

    case InputClientProxy::getId():
        return InputClientProxy::read(reader);

    case help::TermsOfServiceUpdateEmpty::getId():
        return help::TermsOfServiceUpdateEmpty::read(reader);

    case help::TermsOfServiceUpdate::getId():
        return help::TermsOfServiceUpdate::read(reader);

    case InputSecureFileUploaded::getId():
        return InputSecureFileUploaded::read(reader);

    case InputSecureFile::getId():
        return InputSecureFile::read(reader);

    case SecureFileEmpty::getId():
        return SecureFileEmpty::read(reader);

    case SecureFile::getId():
        return SecureFile::read(reader);

    case SecureData::getId():
        return SecureData::read(reader);

    case SecurePlainPhone::getId():
        return SecurePlainPhone::read(reader);

    case SecurePlainEmail::getId():
        return SecurePlainEmail::read(reader);

    case SecureValueTypePersonalDetails::getId():
        return SecureValueTypePersonalDetails::read(reader);

    case SecureValueTypePassport::getId():
        return SecureValueTypePassport::read(reader);

    case SecureValueTypeDriverLicense::getId():
        return SecureValueTypeDriverLicense::read(reader);

    case SecureValueTypeIdentityCard::getId():
        return SecureValueTypeIdentityCard::read(reader);

    case SecureValueTypeInternalPassport::getId():
        return SecureValueTypeInternalPassport::read(reader);

    case SecureValueTypeAddress::getId():
        return SecureValueTypeAddress::read(reader);

    case SecureValueTypeUtilityBill::getId():
        return SecureValueTypeUtilityBill::read(reader);

    case SecureValueTypeBankStatement::getId():
        return SecureValueTypeBankStatement::read(reader);

    case SecureValueTypeRentalAgreement::getId():
        return SecureValueTypeRentalAgreement::read(reader);

    case SecureValueTypePassportRegistration::getId():
        return SecureValueTypePassportRegistration::read(reader);

    case SecureValueTypeTemporaryRegistration::getId():
        return SecureValueTypeTemporaryRegistration::read(reader);

    case SecureValueTypePhone::getId():
        return SecureValueTypePhone::read(reader);

    case SecureValueTypeEmail::getId():
        return SecureValueTypeEmail::read(reader);

    case SecureValue::getId():
        return SecureValue::read(reader);

    case InputSecureValue::getId():
        return InputSecureValue::read(reader);

    case SecureValueHash::getId():
        return SecureValueHash::read(reader);

    case SecureValueErrorData::getId():
        return SecureValueErrorData::read(reader);

    case SecureValueErrorFrontSide::getId():
        return SecureValueErrorFrontSide::read(reader);

    case SecureValueErrorReverseSide::getId():
        return SecureValueErrorReverseSide::read(reader);

    case SecureValueErrorSelfie::getId():
        return SecureValueErrorSelfie::read(reader);

    case SecureValueErrorFile::getId():
        return SecureValueErrorFile::read(reader);

    case SecureValueErrorFiles::getId():
        return SecureValueErrorFiles::read(reader);

    case SecureValueError::getId():
        return SecureValueError::read(reader);

    case SecureValueErrorTranslationFile::getId():
        return SecureValueErrorTranslationFile::read(reader);

    case SecureValueErrorTranslationFiles::getId():
        return SecureValueErrorTranslationFiles::read(reader);

    case SecureCredentialsEncrypted::getId():
        return SecureCredentialsEncrypted::read(reader);

    case account::AuthorizationForm::getId():
        return account::AuthorizationForm::read(reader);

    case account::SentEmailCode::getId():
        return account::SentEmailCode::read(reader);

    case help::DeepLinkInfoEmpty::getId():
        return help::DeepLinkInfoEmpty::read(reader);

    case help::DeepLinkInfo::getId():
        return help::DeepLinkInfo::read(reader);

    case SavedPhoneContact::getId():
        return SavedPhoneContact::read(reader);

    case account::Takeout::getId():
        return account::Takeout::read(reader);

    case PasswordKdfAlgoUnknown::getId():
        return PasswordKdfAlgoUnknown::read(reader);

    case PasswordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::getId():
        return PasswordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::read(reader);

    case SecurePasswordKdfAlgoUnknown::getId():
        return SecurePasswordKdfAlgoUnknown::read(reader);

    case SecurePasswordKdfAlgoPBKDF2HMACSHA512iter100000::getId():
        return SecurePasswordKdfAlgoPBKDF2HMACSHA512iter100000::read(reader);

    case SecurePasswordKdfAlgoSHA512::getId():
        return SecurePasswordKdfAlgoSHA512::read(reader);

    case SecureSecretSettings::getId():
        return SecureSecretSettings::read(reader);

    case InputCheckPasswordEmpty::getId():
        return InputCheckPasswordEmpty::read(reader);

    case InputCheckPasswordSRP::getId():
        return InputCheckPasswordSRP::read(reader);

    case SecureRequiredType::getId():
        return SecureRequiredType::read(reader);

    case SecureRequiredTypeOneOf::getId():
        return SecureRequiredTypeOneOf::read(reader);

    case help::PassportConfigNotModified::getId():
        return help::PassportConfigNotModified::read(reader);

    case help::PassportConfig::getId():
        return help::PassportConfig::read(reader);

    case InputAppEvent::getId():
        return InputAppEvent::read(reader);

    case JsonObjectValue::getId():
        return JsonObjectValue::read(reader);

    case JsonNull::getId():
        return JsonNull::read(reader);

    case JsonBool::getId():
        return JsonBool::read(reader);

    case JsonNumber::getId():
        return JsonNumber::read(reader);

    case JsonString::getId():
        return JsonString::read(reader);

    case JsonArray::getId():
        return JsonArray::read(reader);

    case JsonObject::getId():
        return JsonObject::read(reader);

    case PageTableCell::getId():
        return PageTableCell::read(reader);

    case PageTableRow::getId():
        return PageTableRow::read(reader);

    case PageCaption::getId():
        return PageCaption::read(reader);

    case PageListItemText::getId():
        return PageListItemText::read(reader);

    case PageListItemBlocks::getId():
        return PageListItemBlocks::read(reader);

    case PageListOrderedItemText::getId():
        return PageListOrderedItemText::read(reader);

    case PageListOrderedItemBlocks::getId():
        return PageListOrderedItemBlocks::read(reader);

    case PageRelatedArticle::getId():
        return PageRelatedArticle::read(reader);

    case Page::getId():
        return Page::read(reader);

    case help::SupportName::getId():
        return help::SupportName::read(reader);

    case help::UserInfoEmpty::getId():
        return help::UserInfoEmpty::read(reader);

    case help::UserInfo::getId():
        return help::UserInfo::read(reader);

    case PollAnswer::getId():
        return PollAnswer::read(reader);

    case Poll::getId():
        return Poll::read(reader);

    case PollAnswerVoters::getId():
        return PollAnswerVoters::read(reader);

    case PollResults::getId():
        return PollResults::read(reader);

    case ChatOnlines::getId():
        return ChatOnlines::read(reader);

    case StatsURL::getId():
        return StatsURL::read(reader);

    case ChatAdminRights::getId():
        return ChatAdminRights::read(reader);

    case ChatBannedRights::getId():
        return ChatBannedRights::read(reader);

    case InputWallPaper::getId():
        return InputWallPaper::read(reader);

    case InputWallPaperSlug::getId():
        return InputWallPaperSlug::read(reader);

    case InputWallPaperNoFile::getId():
        return InputWallPaperNoFile::read(reader);

    case account::WallPapersNotModified::getId():
        return account::WallPapersNotModified::read(reader);

    case account::WallPapers::getId():
        return account::WallPapers::read(reader);

    case CodeSettings::getId():
        return CodeSettings::read(reader);

    case WallPaperSettings::getId():
        return WallPaperSettings::read(reader);

    case AutoDownloadSettings::getId():
        return AutoDownloadSettings::read(reader);

    case account::AutoDownloadSettings::getId():
        return account::AutoDownloadSettings::read(reader);

    case EmojiKeyword::getId():
        return EmojiKeyword::read(reader);

    case EmojiKeywordDeleted::getId():
        return EmojiKeywordDeleted::read(reader);

    case EmojiKeywordsDifference::getId():
        return EmojiKeywordsDifference::read(reader);

    case EmojiURL::getId():
        return EmojiURL::read(reader);

    case EmojiLanguage::getId():
        return EmojiLanguage::read(reader);

    case Folder::getId():
        return Folder::read(reader);

    case InputFolderPeer::getId():
        return InputFolderPeer::read(reader);

    case FolderPeer::getId():
        return FolderPeer::read(reader);

    case messages::SearchCounter::getId():
        return messages::SearchCounter::read(reader);

    case UrlAuthResultRequest::getId():
        return UrlAuthResultRequest::read(reader);

    case UrlAuthResultAccepted::getId():
        return UrlAuthResultAccepted::read(reader);

    case UrlAuthResultDefault::getId():
        return UrlAuthResultDefault::read(reader);

    case ChannelLocationEmpty::getId():
        return ChannelLocationEmpty::read(reader);

    case ChannelLocation::getId():
        return ChannelLocation::read(reader);

    case PeerLocated::getId():
        return PeerLocated::read(reader);

    case PeerSelfLocated::getId():
        return PeerSelfLocated::read(reader);

    case RestrictionReason::getId():
        return RestrictionReason::read(reader);

    case InputTheme::getId():
        return InputTheme::read(reader);

    case InputThemeSlug::getId():
        return InputThemeSlug::read(reader);

    case Theme::getId():
        return Theme::read(reader);

    case account::ThemesNotModified::getId():
        return account::ThemesNotModified::read(reader);

    case account::Themes::getId():
        return account::Themes::read(reader);

    case auth::LoginToken::getId():
        return auth::LoginToken::read(reader);

    case auth::LoginTokenMigrateTo::getId():
        return auth::LoginTokenMigrateTo::read(reader);

    case auth::LoginTokenSuccess::getId():
        return auth::LoginTokenSuccess::read(reader);

    case account::ContentSettings::getId():
        return account::ContentSettings::read(reader);

    case messages::InactiveChats::getId():
        return messages::InactiveChats::read(reader);

    case BaseThemeClassic::getId():
        return BaseThemeClassic::read(reader);

    case BaseThemeDay::getId():
        return BaseThemeDay::read(reader);

    case BaseThemeNight::getId():
        return BaseThemeNight::read(reader);

    case BaseThemeTinted::getId():
        return BaseThemeTinted::read(reader);

    case BaseThemeArctic::getId():
        return BaseThemeArctic::read(reader);

    case InputThemeSettings::getId():
        return InputThemeSettings::read(reader);

    case ThemeSettings::getId():
        return ThemeSettings::read(reader);

    case WebPageAttributeTheme::getId():
        return WebPageAttributeTheme::read(reader);

    case MessageUserVote::getId():
        return MessageUserVote::read(reader);

    case MessageUserVoteInputOption::getId():
        return MessageUserVoteInputOption::read(reader);

    case MessageUserVoteMultiple::getId():
        return MessageUserVoteMultiple::read(reader);

    case messages::VotesList::getId():
        return messages::VotesList::read(reader);

    case BankCardOpenUrl::getId():
        return BankCardOpenUrl::read(reader);

    case payments::BankCardData::getId():
        return payments::BankCardData::read(reader);

    case DialogFilter::getId():
        return DialogFilter::read(reader);

    case DialogFilterSuggested::getId():
        return DialogFilterSuggested::read(reader);

    case StatsDateRangeDays::getId():
        return StatsDateRangeDays::read(reader);

    case StatsAbsValueAndPrev::getId():
        return StatsAbsValueAndPrev::read(reader);

    case StatsPercentValue::getId():
        return StatsPercentValue::read(reader);

    case StatsGraphAsync::getId():
        return StatsGraphAsync::read(reader);

    case StatsGraphError::getId():
        return StatsGraphError::read(reader);

    case StatsGraph::getId():
        return StatsGraph::read(reader);

    case MessageInteractionCounters::getId():
        return MessageInteractionCounters::read(reader);

    case stats::BroadcastStats::getId():
        return stats::BroadcastStats::read(reader);

    case help::PromoDataEmpty::getId():
        return help::PromoDataEmpty::read(reader);

    case help::PromoData::getId():
        return help::PromoData::read(reader);

    case VideoSize::getId():
        return VideoSize::read(reader);

    case StatsGroupTopPoster::getId():
        return StatsGroupTopPoster::read(reader);

    case StatsGroupTopAdmin::getId():
        return StatsGroupTopAdmin::read(reader);

    case StatsGroupTopInviter::getId():
        return StatsGroupTopInviter::read(reader);

    case stats::MegagroupStats::getId():
        return stats::MegagroupStats::read(reader);

    case GlobalPrivacySettings::getId():
        return GlobalPrivacySettings::read(reader);

    case help::CountryCode::getId():
        return help::CountryCode::read(reader);

    case help::Country::getId():
        return help::Country::read(reader);

    case help::CountriesListNotModified::getId():
        return help::CountriesListNotModified::read(reader);

    case help::CountriesList::getId():
        return help::CountriesList::read(reader);

    case MessageViews::getId():
        return MessageViews::read(reader);

    case messages::MessageViews::getId():
        return messages::MessageViews::read(reader);

    case messages::DiscussionMessage::getId():
        return messages::DiscussionMessage::read(reader);

    case MessageReplyHeader::getId():
        return MessageReplyHeader::read(reader);

    case MessageReplies::getId():
        return MessageReplies::read(reader);

    case PeerBlocked::getId():
        return PeerBlocked::read(reader);

    case stats::MessageStats::getId():
        return stats::MessageStats::read(reader);

    case GroupCallDiscarded::getId():
        return GroupCallDiscarded::read(reader);

    case GroupCall::getId():
        return GroupCall::read(reader);

    case InputGroupCall::getId():
        return InputGroupCall::read(reader);

    case GroupCallParticipant::getId():
        return GroupCallParticipant::read(reader);

    case phone::GroupCall::getId():
        return phone::GroupCall::read(reader);

    case phone::GroupParticipants::getId():
        return phone::GroupParticipants::read(reader);

    case InlineQueryPeerTypeSameBotPM::getId():
        return InlineQueryPeerTypeSameBotPM::read(reader);

    case InlineQueryPeerTypePM::getId():
        return InlineQueryPeerTypePM::read(reader);

    case InlineQueryPeerTypeChat::getId():
        return InlineQueryPeerTypeChat::read(reader);

    case InlineQueryPeerTypeMegagroup::getId():
        return InlineQueryPeerTypeMegagroup::read(reader);

    case InlineQueryPeerTypeBroadcast::getId():
        return InlineQueryPeerTypeBroadcast::read(reader);

    case messages::HistoryImport::getId():
        return messages::HistoryImport::read(reader);

    case messages::HistoryImportParsed::getId():
        return messages::HistoryImportParsed::read(reader);

    case messages::AffectedFoundMessages::getId():
        return messages::AffectedFoundMessages::read(reader);

    case ChatInviteImporter::getId():
        return ChatInviteImporter::read(reader);

    case messages::ExportedChatInvites::getId():
        return messages::ExportedChatInvites::read(reader);

    case messages::ExportedChatInvite::getId():
        return messages::ExportedChatInvite::read(reader);

    case messages::ExportedChatInviteReplaced::getId():
        return messages::ExportedChatInviteReplaced::read(reader);

    case messages::ChatInviteImporters::getId():
        return messages::ChatInviteImporters::read(reader);

    case ChatAdminWithInvites::getId():
        return ChatAdminWithInvites::read(reader);

    case messages::ChatAdminsWithInvites::getId():
        return messages::ChatAdminsWithInvites::read(reader);

    case messages::CheckedHistoryImportPeer::getId():
        return messages::CheckedHistoryImportPeer::read(reader);

    case phone::JoinAsPeers::getId():
        return phone::JoinAsPeers::read(reader);

    case phone::ExportedGroupCallInvite::getId():
        return phone::ExportedGroupCallInvite::read(reader);

    case GroupCallParticipantVideoSourceGroup::getId():
        return GroupCallParticipantVideoSourceGroup::read(reader);

    case GroupCallParticipantVideo::getId():
        return GroupCallParticipantVideo::read(reader);

    case stickers::SuggestedShortName::getId():
        return stickers::SuggestedShortName::read(reader);

    case BotCommandScopeDefault::getId():
        return BotCommandScopeDefault::read(reader);

    case BotCommandScopeUsers::getId():
        return BotCommandScopeUsers::read(reader);

    case BotCommandScopeChats::getId():
        return BotCommandScopeChats::read(reader);

    case BotCommandScopeChatAdmins::getId():
        return BotCommandScopeChatAdmins::read(reader);

    case BotCommandScopePeer::getId():
        return BotCommandScopePeer::read(reader);

    case BotCommandScopePeerAdmins::getId():
        return BotCommandScopePeerAdmins::read(reader);

    case BotCommandScopePeerUser::getId():
        return BotCommandScopePeerUser::read(reader);

    default:
        throw std::runtime_error("Unknown id received: " + std::to_string(id));
        break;
    }
}
