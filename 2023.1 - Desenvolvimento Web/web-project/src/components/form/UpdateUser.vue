<script setup>
import { ref } from 'vue';
import { Auth } from '../../stores/user.js';
import { api } from '../../apiConfig';

const auth = Auth()
const thisPassword = ref(null)

const updateSucess = ref([])
const updateFail = ref([])

async function userConfig() {

    try {
        if (thisPassword.value) {
            await api.put(`/users/${auth.id}`, {

                username: auth.username,
                email: auth.email,
                contato: auth.contato,
                password: thisPassword.value
            }
                , {
                    headers: {
                        Authorization: `Bearer ${auth.token}`
                    }
                }).then(response => {
                    if (response.status == '200') {
                        updateSucess.value.click()
                    } else {
                        console.log(thisPassword.value)
                        console.log(response)
                        updateFail.value.click()
                    }
                })
        } else {
            await api.put(`/users/${auth.id}`, {

                username: auth.username,
                email: auth.email,
                contato: auth.contato,
            }
                , {
                    headers: {
                        Authorization: `Bearer ${auth.token}`
                    }
                }).then(response => {
                    if (response.status == '200') {
                        updateSucess.value.click()
                    } else {
                        console.log(thisPassword.value)
                        console.log(response)
                        updateFail.value.click()
                    }
                })


        }
    } catch (error) {
        updateFail.value.click()
    }
}



</script>


<template>
    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#updateSucess" ref="updateSucess"
        style="display: none;">
    </button>
    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#updateFail" ref="updateFail" style="display: none;">
    </button>



    <form @submit.prevent="userConfig()" class="float-start">
        <div class="mb-3">
            <h5>Atualizar Dados</h5>
        </div>
        <div class="container border align-text-itens" id="atualizarDados">
            <div class="row my-2">
                <label for="userName">Nome de Usuário</label>
                <input autocomplete="off" type="text" class="form-control mb-3 mx-2" v-model="auth.username" id="userName">
            </div>
            <div class="row">
                <label for="userEmail">Email</label>
                <input autocomplete="off" type="text" v-model="auth.email" class="form-control mb-3 mx-2" id="userEmail">
            </div>
            <div class="row">
                <label for="userContact">Contato</label>
                <input autocomplete="off" type="text" v-model="auth.contato" class="form-control mb-3 mx-2" id="userContact">
            </div>
            <div class="row">
                <label for="userPassword">Senha</label>
                <input autocomplete="off" type="password" v-model="thisPassword" class="form-control mb-3 mx-2" id="userPassword">
            </div>
            <div class="" style="text-align: center;">
                <button type="submit" class="btn btn-primary mt-3 mb-2">Atualizar</button>
            </div>
        </div>

    </form>

    <div style="text-align: end;">
        <button class="btn btn-danger mt-3" type="button" data-bs-toggle="offcanvas"
            data-bs-target="#delUserConfirm">Deletar Conta</button>
    </div>
</template>