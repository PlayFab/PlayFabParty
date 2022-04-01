#pragma once

// Represents data that can be sent to endpoints.
// Currently defines the UserDisplayName message to pass the display name to other chat controls.

namespace PartySample
{

    // The type of message to be sent. Should always be UserDisplayName.
    enum class NetworkMessageType
    {
        Unknown,
        UserDisplayName
    };

    // The data class used to package the user display name for transfer as an endpoint message.
    class NetworkMessage
    {
    public:
        NetworkMessage();
        NetworkMessage(NetworkMessageType type, unsigned data);
        NetworkMessage(NetworkMessageType type, const std::string& data);
        NetworkMessage(NetworkMessageType type, const std::vector<uint8_t>& data);
        NetworkMessage(const std::vector<uint8_t>& data);
        ~NetworkMessage();

        NetworkMessageType MessageType() const { return m_type; }
        void MessageType(NetworkMessageType type) { m_type = type; }

        inline const std::vector<uint8_t>& RawData() { return m_data; }
        inline void RawData(const std::vector<uint8_t>& data) { m_data = data; }

        std::string StringValue();
        unsigned UnsignedValue();

        std::vector<uint8_t> Serialize() const;

        inline
        static
        Party::PartyDataBuffer
        PartyStringAsDataBuffer(
            PartyString s
            )
        {
            return { s, static_cast<uint32_t>((strlen(s) + 1) * sizeof(s[0])) };
        }

    private:
        NetworkMessageType m_type;
        std::vector<uint8_t> m_data;
    };

}
