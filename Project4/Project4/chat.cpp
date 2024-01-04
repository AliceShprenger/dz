#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    for (int i = 0; i < SIZE; i++)
    {
        if (data[hash_func(_login, i)].status == enPairStatus::free)
        {
            data[hash_func(_login, i)] = AuthData(_login, sha1(_pass, pass_length));
            data[hash_func(_login, i)].status = enPairStatus::engaged;
            break;
        }
    }
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // ¬аш код
    // Ќужно вернуть true в случае успешного логина
    int i = 0;
    int T = 0;
    for (; i < SIZE; i++) {
        AuthData& ad = data[hash_func(_login, i)];
        if (!strcmp(ad.login, _login)) {
            break;
        }
    }
    if (T==0) return false;

    uint* digest = sha1(_pass, pass_length);

    bool cmpHashes = !memcmp(
        data[i].pass_sha1_hash,
        digest,
        SHA1HASHLENGTHBYTES);
    delete[] digest;

    return cmpHashes;
}

int Chat::hfunc(int val)
{
    const double A = 0.7;
    const int M = 10;
    return int(M * (A * val - int(A * val)));
}

int Chat::hash_func(char* fr_name, int offset)
{
    // вычисл€ем индекс
    int sum = 0, i = 0;
    for (; i < strlen(fr_name); i++) {
        sum += fr_name[i];
    }
    sum = hfunc(sum);
    // линейные пробы
    return (sum % SIZE + offset * offset) % SIZE;
}
