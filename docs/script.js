document.addEventListener('DOMContentLoaded', () => {
    const form = document.getElementById('atividade-form');
    const choiceSelect = document.getElementById('choice');
    const inputFieldsDiv = document.getElementById('input-fields');
    const resultText = document.getElementById('result-text');

    choiceSelect.addEventListener('change', () => {
        const choice = choiceSelect.value;
        inputFieldsDiv.innerHTML = '';

        if (['1', '2', '3', '4', '7', '8'].includes(choice)) {
            const inputN = document.createElement('input');
            inputN.type = 'number';
            inputN.name = 'n';
            inputN.placeholder = 'Digite um número';
            inputFieldsDiv.appendChild(inputN);
        } else if (['5', '6'].includes(choice)) {
            const inputA = document.createElement('input');
            inputA.type = 'number';
            inputA.name = 'a';
            inputA.placeholder = 'Digite o primeiro número';
            inputFieldsDiv.appendChild(inputA);

            const inputB = document.createElement('input');
            inputB.type = 'number';
            inputB.name = 'b';
            inputB.placeholder = 'Digite o segundo número';
            inputFieldsDiv.appendChild(inputB);
        }
    });

    form.addEventListener('submit', async (event) => {
        event.preventDefault();
        const formData = new FormData(form);
        const choice = formData.get('choice');
        const input = {
            n: formData.get('n') || 0,
            a: formData.get('a') || 0,
            b: formData.get('b') || 0
        };

        try {
            const response = await fetch('https://2024md2.netlify.app', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ choice, input })
            });
            const data = await response.json();
            resultText.textContent = data.result;
        } catch (error) {
            console.error('Error fetching data:', error);
            resultText.textContent = 'Erro ao buscar dados.';
        }
    });
});