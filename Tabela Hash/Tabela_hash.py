class TwoLevelHashTable:
    """
    Implementação de Tabela Hash com encadeamento separado duplo:
    - Primeiro nível: vetor de tamanho 10.
    - Segundo nível: para cada entrada do primeiro nível, um vetor de n/10 listas.
    """
    def __init__(self, capacity: int):
        if capacity < 10:
            raise ValueError("Capacity must be at least 10")
        self.capacity = capacity
        self.first_size = 10
        # tamanho de cada tabela secundária
        self.second_size = capacity // self.first_size
        # inicializa primeiro e segundo níveis
        self.table = [ [ [] for _ in range(self.second_size) ] for _ in range(self.first_size) ]

    def hash1(self, key) -> int:
        """Hash do primeiro nível: chave para 0..9"""
        return hash(key) % self.first_size

    def hash2(self, key) -> int:
        """Hash do segundo nível: chave para 0..(n/10 - 1)"""
        # usa outro método, por exemplo, divisão seguida de módulo
        return (hash(key) // self.first_size) % self.second_size

    def insert(self, key, value):
        """Insere (ou atualiza) um objeto na tabela a partir de chave única"""
        i = self.hash1(key)
        j = self.hash2(key)
        bucket = self.table[i][j]
        # verifica se chave já existe e atualiza
        for idx, (k, v) in enumerate(bucket):
            if k == key:
                bucket[idx] = (key, value)
                return
        # senão, insere no final da lista
        bucket.append((key, value))

    def get(self, key):
        """Recupera objeto a partir da chave única. Levanta KeyError se não encontrado."""
        i = self.hash1(key)
        j = self.hash2(key)
        bucket = self.table[i][j]
        for k, v in bucket:
            if k == key:
                return v
        raise KeyError(f"Chave {key!r} não encontrada")

    def __repr__(self):
        lines = []
        for i, second in enumerate(self.table):
            for j, bucket in enumerate(second):
                if bucket:
                    lines.append(f"[{i}][{j}] -> {bucket}")
        return "\n".join(lines)


# Exemplo de uso
if __name__ == '__main__':
    # cap = número de objetos esperados
    cap = 100
    th = TwoLevelHashTable(cap)

    # insere alguns valores
    th.insert('ana', 25)
    th.insert('bruno', {'idade': 30, 'cidade': 'Recife'})
    th.insert(42, 'resposta')

    # atualiza
    th.insert('ana', 26)

    # recupera
    print('Ana:', th.get('ana'))
    print('Bruno:', th.get('bruno'))
    print('42:', th.get(42))

    # tenta recuperar chave inexistente
    try:
        th.get('Carlos')
    except KeyError as e:
        print(e)
