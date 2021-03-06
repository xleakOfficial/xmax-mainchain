#include "pro/types/generictypes.hpp"
#include "pro/utils/sha256.hpp"
#include "pro/crypto/Base58String.hpp"

#include <cassert>

namespace pro
{
	static const char* pszBase58 = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

bool DecodeBase58(const char* psz, std::vector<unsigned char>& vch)
{
	// Skip leading spaces.
	while (*psz && isspace(*psz))
	{
		psz++;
	}
		
	// Skip and count leading '1's.
	int zeroes = 0;
	int length = 0;
	while (*psz == '1') 
	{
		zeroes++;
		psz++;
	}
	// Allocate enough space in big-endian base256 representation.
	int size = strlen(psz) * 733 / 1000 + 1; // log(58) / log(256), rounded up.
	std::vector<unsigned char> b256(size);
	// Process the characters.
	while (*psz && !isspace(*psz)) 
	{
		// Decode base58 character
		const char* ch = strchr(pszBase58, *psz);
		if (ch == NULL)
			return false;
		// Apply "b256 = b256 * 58 + ch".
		int carry = ch - pszBase58;
		int i = 0;
		for 
		(
			std::vector<unsigned char>::reverse_iterator it = b256.rbegin();
			(carry != 0 || i < length) && (it != b256.rend());
			++it, ++i
			) {
			carry += 58 * (*it);
			*it = carry % 256;
			carry /= 256;
		}
		assert(carry == 0);
		length = i;
		psz++;
	}
	// Skip trailing spaces.
	while (isspace(*psz))
		psz++;
	if (*psz != 0)
		return false;
	// Skip leading zeroes in b256.
	std::vector<unsigned char>::iterator it = b256.begin() + (size - length);
	while (it != b256.end() && *it == 0)
		it++;
	// Copy result into output vector.
	vch.reserve(zeroes + (b256.end() - it));
	vch.assign(zeroes, 0x00);
	while (it != b256.end())
		vch.push_back(*(it++));
	return true;
}

std::string EncodeBase58(const unsigned char* pbegin, const unsigned char* pend)
{
	// Skip & count leading zeroes.
	int zeroes = 0;
	int length = 0;
	while (pbegin != pend && *pbegin == 0) {
		pbegin++;
		zeroes++;
	}
	// Allocate enough space in big-endian base58 representation.
	int size = (pend - pbegin) * 138 / 100 + 1; // log(256) / log(58), rounded up.
	std::vector<unsigned char> b58(size);
	// Process the bytes.
	while (pbegin != pend) {
		int carry = *pbegin;
		int i = 0;
		// Apply "b58 = b58 * 256 + ch".
		for (std::vector<unsigned char>::reverse_iterator it = b58.rbegin(); (carry != 0 || i < length) && (it != b58.rend()); it++, i++) {
			carry += 256 * (*it);
			*it = carry % 58;
			carry /= 58;
		}

		assert(carry == 0);
		length = i;
		pbegin++;
	}
	// Skip leading zeroes in base58 result.
	std::vector<unsigned char>::iterator it = b58.begin() + (size - length);
	while (it != b58.end() && *it == 0)
		it++;
	// Translate the result into a string.
	std::string str;
	str.reserve(zeroes + (b58.end() - it));
	str.assign(zeroes, '1');
	while (it != b58.end())
		str += pszBase58[*(it++)];
	return str;
}

std::string EncodeBase58(const std::vector<unsigned char>& vch)
{
	return EncodeBase58(&vch[0], &vch[0] + vch.size());
}

bool DecodeBase58(const std::string& str, std::vector<unsigned char>& vchRet)
{
	return DecodeBase58(str.c_str(), vchRet);
}

std::string EncodeBase58Check(const std::vector<unsigned char>& vchIn)
{
	// add 4-byte hash check to the end
	std::vector<unsigned char> vch(vchIn);
	DoubleSHA256 sha256;
	sha256.Hash(vch);	
	vch.insert(vch.end(), sha256.Data(), sha256.Data() + 4);
	return EncodeBase58(vch);
}

bool DecodeBase58Check(const char* psz, std::vector<unsigned char>& vchRet)
{
	if (!DecodeBase58(psz, vchRet) ||
		(vchRet.size() < 4)) 
	{
		vchRet.clear();
		return false;
	}
	// re-calculate the checksum, insure it matches the included 4-byte checksum
	DoubleSHA256 sha256;
	sha256.Hash(vchRet.begin(), vchRet.end() - 4);

	if (memcmp(const_cast<unsigned char*>(sha256.Data()), &vchRet.end()[-4], 4) != 0) 
	{
		vchRet.clear();
		return false;
	}
	vchRet.resize(vchRet.size() - 4);
	return true;
}

bool DecodeBase58Check(const std::string& str, std::vector<unsigned char>& vchRet)
{
	return DecodeBase58Check(str.c_str(), vchRet);
}

void Base58Data::SetData(const std::vector<unsigned char> &vchVersionIn, const void* pdata, size_t nSize)
{
	vchVersion_ = vchVersionIn;
	vchData_.resize(nSize);
	if (!vchData_.empty())
	{
		memcpy(&vchData_[0], pdata, nSize);
	}
		
}

void Base58Data::SetData(const std::vector<unsigned char> &vchVersionIn, const unsigned char *pbegin, const unsigned char *pend)
{
	SetData(vchVersionIn, (void*)pbegin, pend - pbegin);
}

bool Base58Data::SetStringWithVersionBytes(const char* psz, unsigned int nVersionBytes)
{	
	std::vector<unsigned char> vchTemp;
	bool rc58 = DecodeBase58Check(psz, vchTemp);

	if ((!rc58) || (vchTemp.size() < nVersionBytes)) 
	{
		vchData_.clear();
		vchVersion_.clear();
		return false;
	}

	vchVersion_.assign(vchTemp.begin(), vchTemp.begin() + nVersionBytes);

	
	vchData_.resize(vchTemp.size() - nVersionBytes);
	if (!vchData_.empty()) 
		memcpy(&vchData_[0], &vchTemp[nVersionBytes], vchData_.size());

	return true;
}

bool Base58Data::SetString(const std::string& str)
{
	return SetString(str.c_str());
}

bool Base58Data::SetBase58string(const Base58String& str)
{
	return SetString(str.c_str());
}

std::string Base58Data::ToString() const
{
	std::vector<unsigned char> vch = vchVersion_;
	vch.insert(vch.end(), vchData_.begin(), vchData_.end());
	return EncodeBase58Check(vch);
}

int Base58Data::CompareTo(const Base58Data& b58) const
{
	if (vchVersion_ < b58.vchVersion_)
		return -1;
	if (vchVersion_ > b58.vchVersion_)
		return 1;
	if (vchData_ < b58.vchData_)
		return -1;
	if (vchData_ > b58.vchData_)
		return 1;
	return 0;
}

}