import React, { useState } from 'react';
import axios from 'axios';

const Menu = () => {
    const [choice, setChoice] = useState('');
    const [result, setResult] = useState('');
    const [input, setInput] = useState({ n: '', a: '', b: '' });

    const handleInputChange = (e) => {
        setInput({ ...input, [e.target.name]: e.target.value });
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        try {
            const response = await axios.post('https://2024md2.netlify.app', { choice, input });
            setResult(response.data.result);
        } catch (error) {
            console.error(error);
        }
    };

    return (
        <div>
            <h1>Menu</h1>
            <form onSubmit={handleSubmit}>
                <label>
                    Escolha uma opção:
                    <select value={choice} onChange={(e) => setChoice(e.target.value)}>
                        <option value="">Selecione</option>
                        <option value="1">Calcular n! (Fatorial)</option>
                        <option value="2">Sequência de Fibonacci</option>
                        <option value="3">Imprimir números naturais de 1 a n</option>
                        <option value="4">Somatório de 1 a n</option>
                        <option value="5">Algoritmo de Euclides para o cálculo do MDC</option>
                        <option value="6">Calcular o MMC(a,b)</option>
                        <option value="7">Tabela Z_n para adição modular</option>
                        <option value="8">Tabela Z_n para multiplicação modular</option>
                        <option value="9">Sair</option>
                    </select>
                </label>
                {choice && (
                    <div>
                        {['1', '2', '3', '4', '7', '8'].includes(choice) && (
                            <label>
                                Digite um número:
                                <input type="number" name="n" value={input.n} onChange={handleInputChange} />
                            </label>
                        )}
                        {['5', '6'].includes(choice) && (
                            <>
                                <label>
                                    Digite o primeiro número:
                                    <input type="number" name="a" value={input.a} onChange={handleInputChange} />
                                </label>
                                <label>
                                    Digite o segundo número:
                                    <input type="number" name="b" value={input.b} onChange={handleInputChange} />
                                </label>
                            </>
                        )}
                    </div>
                )}
                <button type="submit">Enviar</button>
            </form>
            {result && <div><h2>Resultado:</h2><p>{result}</p></div>}
        </div>
    );
};

export default Menu;