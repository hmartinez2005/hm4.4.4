<!DOCTYPE html>
<html lang = "es">
<head>
<meta charset = "UTF-8">
<meta name = "viewport" content = "width=device-width, initial-scale=1.0">
<title>Formulario de Pedido de Pizza< / title>
<link rel = "stylesheet" href = "styles.css">
< / head>
<body>
<h1>Formulario de Pedido de Pizza< / h1>
<form id = "pedidoForm">
<label for = "cliente">Cliente:< / label>
<input type = "text" id = "cliente" name = "cliente" required>

<label for = "telefono">Teléfono : < / label>
<input type = "tel" id = "telefono" name = "telefono" required>

<label for = "direccion">Dirección : < / label>
<input type = "text" id = "direccion" name = "direccion" required>

<h2>Tipos de Pizza< / h2>
<div id = "tiposPizza">
<button type = "button" onclick = "seleccionarPizza('Margarita', 10)">Margarita - $10< / button>
<button type = "button" onclick = "seleccionarPizza('Pepperoni', 12)">Pepperoni - $12< / button>
<button type = "button" onclick = "seleccionarPizza('Hawaiana', 15)">Hawaiana - $15< / button>
< / div>

<h2>Pedido< / h2>
<table>
<thead>
<tr>
<th>Descripción< / th>
<th>Cant.< / th>
<th>Subtotal< / th>
< / tr>
< / thead>
<tbody id = "pedidoDetalle">
<!--Detalles del pedido se agregarán aquí-->
< / tbody>
< / table>

<label for = "total">Total:< / label>
<input type = "text" id = "total" name = "total" readonly>

<label for = "iva">I.V.A. (12 %) : < / label>
<input type = "text" id = "iva" name = "iva" readonly>

<label for = "neto">Neto a Cancelar : < / label>
<input type = "text" id = "neto" name = "neto" readonly>

<label for = "formaPago">Forma de Pago : < / label>
<select id = "formaPago" name = "formaPago" onchange = "calcularDescuento()">
<option value = "credito">Crédito< / option>
<option value = "debito">Débito< / option>
< / select>

<button type = "button" onclick = "nuevoPedido()">Nuevo Pedido< / button>
< / form>

<script src = "script.js">< / script>
< / body>
< / html>
Código generado por IA.Revisar y usar cuidadosamente.Más información sobre preguntas frecuentes.
2. Estilos CSS
CSS

/* styles.css */
body{
    font - family: Arial, sans - serif;
    margin: 20px;
}

h1, h2{
    color: #333;
}

form{
    max - width: 600px;
    margin: auto;
}

label{
    display: block;
    margin - top: 10px;
}

input, select, button{
    width: 100 %;
    padding: 8px;
    margin - top: 5px;
}

table{
    width: 100 %;
    margin - top: 10px;
    border - collapse: collapse;
}

th, td{
    border: 1px solid #ddd;
    padding: 8px;
    text - align: left;
}
Código generado por IA.Revisar y usar cuidadosamente.Más información sobre preguntas frecuentes.
3. Lógica JavaScript
JavaScript

// script.js
let numeroPedido = 0;

function seleccionarPizza(tipo, precio) {
    const cantidad = prompt(`Ingrese la cantidad de pizzas de tipo ${ tipo }:`);
    if (cantidad && !isNaN(cantidad) && cantidad > 0) {
        agregarPedido(tipo, cantidad, precio);
    }
}

function agregarPedido(tipo, cantidad, precio) {
    const pedidoDetalle = document.getElementById('pedidoDetalle');
    const subtotal = cantidad * precio;

    const row = document.createElement('tr');
    row.innerHTML = `
        <td>${ tipo }< / td>
        <td>${ cantidad }< / td>
        <td>${ subtotal.toFixed(2) }< / td>
        `;
        pedidoDetalle.appendChild(row);

    actualizarTotales();
}

function actualizarTotales() {
    const filas = document.querySelectorAll('#pedidoDetalle tr');
    let total = 0;

    filas.forEach(fila = > {
        const subtotal = parseFloat(fila.cells[2].innerText);
        total += subtotal;
    });

    const iva = total * 0.12;
    const neto = total + iva;

    document.getElementById('total').value = total.toFixed(2);
    document.getElementById('iva').value = iva.toFixed(2);
    document.getElementById('neto').value = neto.toFixed(2);
}

function calcularDescuento() {
    const formaPago = document.getElementById('formaPago').value;
    let neto = parseFloat(document.getElementById('neto').value);

    if (formaPago == = 'debito') {
        neto *= 0.90;
    }

    document.getElementById('neto').value = neto.toFixed(2);
}

function nuevoPedido() {
    document.getElementById('pedidoDetalle').innerHTML = '';
    document.getElementById('total').value = '';
    document.getElementById('iva').value = '';
    document.getElementById('neto').value = '';
    document.getElementById('cliente').value = '';
    document.getElementById('telefono').value = '';
    document.getElementById('direccion').value = '';
    document.getElementById('formaPago').value = 'credito';

    numeroPedido++;
}