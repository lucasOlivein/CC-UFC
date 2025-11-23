import { defineStore } from 'pinia';
import { ref, computed } from 'vue';
import { api } from '../apiConfig.js'
import router from '../router/index.js'
import { Ads } from './ads.js';





export const Auth = defineStore('auth', {
    state: () => {
        return {
            ads: Ads(),
            anuncios: ref([{ anuncios: null }]),
            id: null,
            username: '',
            email: '',
            contato: '',
            logged: false,
            token: '',
            data: ref([]),
            categorias: ref([]),
            password: null,
            role: '',
            users: ref([null]),
            filterUser: null
        }

    },

    actions: {
        logout() {
            this.$reset();
        },
        async login(email, password) {
            return await api.post('/auth/local?populate=*', {
                identifier: email,
                password: password,
            }).then(response => {

                if (response.status == '200') {
                    this.id = response.data.user.id
                    this.username = response.data.user.username
                    this.email = response.data.user.email
                    this.contato = response.data.user.contato
                    this.data = response.data
                    this.token = response.data.jwt
                    this.logged = true
                    api.get("users/me?populate=role", {
                        headers: {
                            Authorization: `Bearer ${this.token}`,
                        },

                    }).then(response => { this.role = response.data.role.name })
                    return 200
                } else {
                    return response
                }
            }).catch((erro) => { return erro })



        },

        async getUser(id) {
            return await api.get(`users${id}`).then(response => { return response })
        },


        // CRUD do usuario
        register(username, email, contato, password) {
            if (contato == '') {
                contato = null
                console.log("sem contato")
            }
            try {
                return api.post('auth/local/register', {
                    username,
                    email,
                    password,
                    contato,
                }).then(response => {
                    return response.status
                }).catch(erro => { return erro })

            } catch (erro) {
                console.log('here')
            }
        },

        async getUsers() {
            this.users.value = await api.get(`users/?populate=anuncios`
            ).then(response => {
                return response.data
            })
            for (let i = 0; i < this.users.value.length; i++)
                this.users.value[i].deleted = false

            this.filterUser = this.users.value
        },
        updateUser(id, data) {      //UpdateUser
            return api.put(`/users/${id}`, data, {
                headers: {
                    Authorization: `Bearer ${this.token}`
                }
            }
            ).then(response => { return response })

        },

        async deleteUser(id) {
            api.get(`users/${id}?populate=anuncios&&populate=anuncios.photos`, {
                headers: {
                    Authorization: `Bearer ${this.token}`
                }
            }).then(response => {
                const anuncios = response.data.anuncios

                if (anuncios) {
                    for (let i = 0; i < anuncios.length; i++) {
                        this.ads.deleteAd(anuncios[i].id, this.token)
                    }
                }
            }).catch(erro => { return erro })

            return await api.delete(`users/${id}`, {
                headers: {
                    Authorization: `Bearer ${this.token}`
                }
            }).then(response => { return response }).catch(erro => { return erro })


        },
    },


})
