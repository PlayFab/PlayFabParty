#include "pch.h"
#include "NetworkMessages.h"

using namespace PartySample;

NetworkMessage::NetworkMessage() :
    m_type(NetworkMessageType::Unknown)
{
}

NetworkMessage::~NetworkMessage()
{
}

NetworkMessage::NetworkMessage(
    NetworkMessageType type,
    unsigned data
    )
{
    m_type = type;
    m_data.resize(sizeof(unsigned));
    CopyMemory(m_data.data(), &data, sizeof(data));
}

NetworkMessage::NetworkMessage(
    NetworkMessageType type,
    const std::string& data
    )
{
    m_type = type;
    m_data.resize(data.length() * sizeof(char));
    CopyMemory(m_data.data(), reinterpret_cast<const uint8_t*>(data.c_str()), m_data.size());
}

NetworkMessage::NetworkMessage(NetworkMessageType type, const std::vector<uint8_t>& data)
{
    m_type = type;
    m_data = data;
}

NetworkMessage::NetworkMessage(
    const std::vector<uint8_t>& data
    )
{
    if (data.size() < (sizeof(NetworkMessageType) + sizeof(uint8_t)))
    {
        // Invalid message
        return;
    }

    CopyMemory(&m_type, data.data(), sizeof(NetworkMessageType));
    m_data.resize(data.size() - sizeof(NetworkMessageType));
    CopyMemory(m_data.data(), data.data() + sizeof(NetworkMessageType), m_data.size());
}

std::vector<uint8_t>
NetworkMessage::Serialize() const
{
    if (m_type == NetworkMessageType::Unknown || m_data.empty())
    {
        return std::vector<uint8_t>();
    }

    size_t length = sizeof(NetworkMessageType) + m_data.size();
    uint8_t *buffer = new uint8_t[length];

    CopyMemory(buffer, &m_type, sizeof(NetworkMessageType));
    CopyMemory(buffer + sizeof(NetworkMessageType), m_data.data(), m_data.size());

    auto packet = std::vector<uint8_t>(buffer, buffer + length);

    delete [] buffer;

    return packet;
}

std::string NetworkMessage::StringValue()
{
    if (!m_data.empty())
    {
        auto stringData = reinterpret_cast<char *>(m_data.data());
        return std::string(stringData, stringData + (m_data.size() / sizeof(char)));
    }

    return "";
}

unsigned
NetworkMessage::UnsignedValue()
{
    if (!m_data.empty())
    {
        return *(reinterpret_cast<unsigned *>(m_data.data()));
    }

    return 0;
}

